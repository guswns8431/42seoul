/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:42 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 08:06:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream&	operator<<(std::ostream& o, const Data& d)
{
	return (o << "id : "<< d.id_ << std::endl << "name : " << d.name_ << std::endl << "grade : " << d.grade_ << std::endl);
}

void			print_state(Data* p)
{
	std::cout << "id : " << p->id_ << std::endl;
	std::cout << "name : " << p->name_ << std::endl;
	std::cout << "grade : " << p->grade_ << std::endl;
}
