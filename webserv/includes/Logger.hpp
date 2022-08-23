/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:46:14 by hyson             #+#    #+#             */
/*   Updated: 2022/08/17 18:46:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>

# include "./Utilizer.hpp"
# include "./LockGuard.hpp"

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"

class Logger
{
private:
	Mutex *_logger;

	time_t _time;
	struct tm *_time_info;
	struct timeval _time_val;
	char _time_format_buffer[100];

	Logger(const Logger &l);
	Logger &operator=(const Logger &l);

	void print(const std::string &color, const std::string &message) const;
	void log(const std::string &color, const std::string &message);

public:
	Logger(void);
	~Logger(void);

	void debug(const std::string &message);
	void info(const std::string &message);
	void error(const std::string &message);
	void fatal(const std::string &message);
};

#endif
