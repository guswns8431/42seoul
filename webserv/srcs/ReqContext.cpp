/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReqContext.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:35:44 by sanjeon           #+#    #+#             */
/*   Updated: 2022/08/18 19:52:07 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ReqContext.hpp"

ReqContext::ReqContext(Request *request,
					   Client *client,
					   ServContexts *serv_contexts)
	: _resource(request->_target),
	  _request(*request),
	  _listen(*(client->get_listen())),
	  _client(*client),
	  _serv_contexts(*serv_contexts),
	  _serv_context(NULL),
	  _location(NULL)
{
	init();
}

ReqContext::~ReqContext(void) {}

bool ReqContext::is_listen_matched(const Listen &listen) const
{
	return (listen.ip == _listen.ip ||
			listen.ip == "0.0.0.0") &&
		   listen.port == _listen.port;
}

bool ReqContext::is_target_exactly_matched(const Location &location) const
{
	return location._uri == _resource;
}

bool ReqContext::is_target_prefix_matched(const Location &location) const
{
	return _resource.find(location._uri) == 0;
}

bool ReqContext::is_location_candidate(const Location &location) const
{
	return !_location ||
		   (_location &&
			_location->_uri.length() < location._uri.length());
}

bool ReqContext::is_method_acceptable(const std::string &method) const
{
	const Methods &methods = _location->_methods;
	if (methods.empty())
	{
		return true;
	}
	if (std::find(methods.begin(), methods.end(), method) != methods.end())
	{
		return true;
	}
	return false;
}

void ReqContext::iterate_in_serv_context(ServContext *serv_context,
										 ServContextPtrs *matched)
{
	for (Listens::const_iterator it = serv_context->get_listens().begin(); it != serv_context->get_listens().end(); it++)
	{
		if (is_listen_matched(*it))
		{
			matched->push_back(serv_context);
			break;
		}
	}
}

void ReqContext::iterate_in_matched(ServContextPtrs &matched)
{
	std::string host_name = _request._headers
								.at("Host")
								.substr(0, _request._headers.at("Host").find(':'));
	for (ServContextPtrs::iterator fit = matched.begin(); fit != matched.end(); fit++)
	{
		ServerNames &names = (*fit)->get_server_names();
		for (ServerNames::iterator sit = names.begin(); sit != names.end(); sit++)
		{
			if (*sit == host_name)
			{
				_serv_context = *fit;
				return;
			}
		}
	}
	_serv_context = matched.front();
}

void ReqContext::set_serv_context_on_request(void)
{
	ServContextPtrs matched;
	for (ServContexts::iterator it = _serv_contexts.begin(); it != _serv_contexts.end(); it++)
	{
		iterate_in_serv_context(&(*it), &matched);
	}
	if (matched.size() == 1)
	{
		_serv_context = matched.front();
		return;
	}
	iterate_in_matched(matched);
}

void ReqContext::case_prefix_matched(Location *location)
{
	if (is_location_candidate(*location))
	{
		_location = location;
	}
}

void ReqContext::iterate_locations_in_serv_context(void)
{
	for (Locations::iterator it = _serv_context->_locations.begin(); it != _serv_context->_locations.end(); it++)
	{
		if (is_target_prefix_matched(*it))
		{
			case_prefix_matched(&(*it));
		}
	}
}

void ReqContext::set_resource_from_target(void)
{
	_resource.erase(0, _location->_uri.length());
}

void ReqContext::set_location_on_request(void)
{
	if (_request.is_header_validated())
	{
		iterate_locations_in_serv_context();
	}
	if (!_location)
	{
		_location = _serv_context;
	}
	else
	{
		set_resource_from_target();
	}
}

void ReqContext::init(void)
{
	set_serv_context_on_request();
	set_location_on_request();
}

void ReqContext::reset_to_redirected_location(const std::string &target)
{
	_resource = target;
	set_location_on_request();
}

bool ReqContext::get_autoindex(void) const
{
	return _location->_is_autoindex_on;
}

std::size_t ReqContext::get_client_max_body_size(void) const
{
	return _location->_client_max_body_size;
}

const std::string &ReqContext::get_uri(void) const
{
	return _location->_uri;
}

const std::string &ReqContext::get_root(void) const
{
	return _location->_root;
}

const std::string &ReqContext::get_upload(void) const
{
	return _location->_upload;
}

const std::string &ReqContext::get_cgi_bin(void) const
{
	return _location->_cgi_bin;
}

const std::string &ReqContext::get_auth(void) const
{
	return _location->_credentials;
}

const Indexes &ReqContext::get_indexes(void) const
{
	return _location->_indexes;
}

const Methods &ReqContext::get_methods(void) const
{
	return _location->_methods;
}

const std::string &ReqContext::get_method(void) const
{
	return _request._method;
}

const Client &ReqContext::get_client(void) const
{
	return _client;
}

const CGIs &ReqContext::get_cgis(void) const
{
	return _location->_cgis;
}

const ErrorPages &ReqContext::get_error_pages(void) const
{
	return _location->_error_pages;
}

const Headers &ReqContext::get_headers(void) const
{
	return _request._headers;
}

const std::string &ReqContext::get_cgi(const std::string &key) const
{
	return _location->_cgis[key];
}

const std::string &ReqContext::get_error_page(int code) const
{
	return _location->_error_pages[code];
}

const std::string &ReqContext::get_header(const std::string &key) const
{
	return _request._headers[key];
}

const std::string &ReqContext::get_body(void) const
{
	return _request._body;
}

const std::string &ReqContext::get_query_string(void) const
{
	return _request._query_string;
}

const std::string &ReqContext::get_resource(void) const
{
	return _resource;
}

const std::string &ReqContext::get_target(void) const
{
	return _request._target;
}

const std::string &ReqContext::get_protocol(void) const
{
	return _request._protocol;
}

const std::string &ReqContext::get_host(void) const
{
	return _listen.ip;
}

std::uint16_t ReqContext::get_port(void) const
{
	return _listen.port;
}

void ReqContext::set_method(const std::string &method)
{
	_request._method = method;
}
