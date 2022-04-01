/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:32:08 by hyson             #+#    #+#             */
/*   Updated: 2022/04/01 11:54:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static bool	CheckInput(std::string filename, std::string s1, std::string s2)
{
	if (filename.empty() || s1.empty() || s2.empty())
		return (false);
}

static bool	CheckFile(std::ifstream in, std::ofstream out)
{
	if (in.fail())
		return (false);
	if (out.fail())
		return (false);
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
	int pos = 0;

	pos = str.find(s1, pos);
	if (pos == std::string::npos)
	{
		std::cout << "not found" << std::endl;
		exit(1);
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
		out << replace() << std::endl;
	in.close();
	out.close();
}
	//getline으로 입력받고 replace하고 out에 넣기
