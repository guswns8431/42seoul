/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:22:19 by hyson             #+#    #+#             */
/*   Updated: 2022/08/17 21:20:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <string>
# include <iostream>

# include "./Mimes.hpp"
# include "./Logger.hpp"
# include "./Parser.hpp"
# include "./Utilizer.hpp"
# include "./Exception.hpp"
# include "./Server.hpp"

class Engine
{
private:
	int _i;
	int _argc;
	char **_argv;
	Parser *_parser;
	Options _options;
	Workers _workers;

	Engine(void);
	Engine(const Engine &e);
	Engine &operator=(const Engine &e);

	std::string guide(void);

	void init_options(void);
	void parse_option(void);
	void parse_argument(void);
	void print_guide_and_exit(void);

	bool is_option(void);
	bool is_option_available(const std::string &option) const;
	bool is_too_many_argument(void) const;
	bool is_help_option_on(void) const;

public:
	Engine(int argc, char **argv);
	~Engine(void);

	static Logger logger;
	static Mimes mimes;
	static StatusCodes status_codes;
	static Mutex server_controller;
	static Mutex connection_controller;
	static Mutex response_controller;

	void launch(void);
};

void *run_servers(void *arg);

#endif
