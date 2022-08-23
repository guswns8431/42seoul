/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:17:16 by sanjeon           #+#    #+#             */
/*   Updated: 2022/08/18 05:52:08 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

#include "./Utilizer.hpp"
#include "./Request.hpp"
#include "./Response.hpp"
#include "./ReqContext.hpp"

class Request;
class ReqContext;
class Response;

class Client {
 private:
  int _fd;
  int _worker_id;
  bool _is_connectable;
  std::string _addr;
  Listen& _listen;

  ReqContext *_req_context;
  Request *_req;
  Response *_res;

  void init_req_context(ServContexts *servers);
  void build_response_and_check_redirection(void);

  Client(void);
  Client(const Client& c);
  const Client& operator=(const Client& c);

 public:
  Client(int fd,
        int worker_id,
        bool is_connectable,
        const std::string& addr,
        Listen *listen);
  ~Client(void);

  void clear(void);
  void init_response(int code, ServContexts *servers);

  bool is_timeout(void);
  bool is_connectable(void) const;
  Listen *get_listen(void);
  const std::string& get_addr(void) const;

  ReqContext *get_req_context(void) const;
  Request *get_request(void);
  Response *get_response(void) const;
};

#endif
