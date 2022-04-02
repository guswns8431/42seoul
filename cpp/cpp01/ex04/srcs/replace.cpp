/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:32:08 by hyson             #+#    #+#             */
/*   Updated: 2022/04/02 15:55:25 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static bool	CheckInput(std::string filename, std::string s1, std::string s2)
{
	if (filename.empty() || s1.empty() || s2.empty())
		return (false);
	return (true);
}

static bool	CheckFile(std::ifstream& in, std::ofstream& out)
{
	if (in.fail())
		return (false);
	if (out.fail())
		return (false);
	return (true);
}

static void	OpenError(void)
{
	errno = 2;
	perror("file");
	exit(1);
}

static std::string replace(std::string str, std::string s1, std::string s2)
{
	std::string res = "";
	std::string remainder = "";
	size_t pos = 0;

	pos = str.find(s1, pos);
	if (pos == std::string::npos)
	{
		std::cout << RED << "not found" << EOC << std::endl;
		exit(1);
	}
	while (true)
	{
		if (pos == std::string::npos)
			break ;
		res = str.substr(0, pos) + s2;
		remainder = str.substr(pos + s1.size());
		pos += s2.size();
		str = res + remainder;
		pos = str.find(s1, pos);
	}
	std::cout << YELLOW << "process" << EOC << " is " << GREEN << "done" << EOC << std::endl;
	return (str);
}

void	ReplaceProcess(std::string filename, std::string s1, std::string s2)
{
	std::string str;

	if (!CheckInput(filename, s1, s2))
		ExitInvalidArg();
	std::ifstream in(filename);
	std::ofstream out(filename + ".replace", std::ios::out);
	if (!CheckFile(in, out))
		OpenError();
	while (std::getline(in, str))
		out << replace(str, s1, s2) << std::endl;
	in.close();
	out.close();
}
