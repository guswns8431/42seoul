/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:08:30 by hyson             #+#    #+#             */
/*   Updated: 2022/04/02 17:28:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl H;

	H.complain("DEBUG");
	H.complain("INFO");
	H.complain("WARNING");
	H.complain("ERROR");
	return (0);
}
