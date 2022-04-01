/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:31:48 by hyson             #+#    #+#             */
/*   Updated: 2022/03/26 17:38:09 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static	void	ExitInvalidArg(void)
{
	errno = 22;
	perror("arg");
	exit(1);
}

int main(int argc, char **argv)
{

	if (argc != 4)
		ExitInvalidArg();
	ReplaceProcess(argv[1], argv[2], argv[3]);
	return (0);
}
	
