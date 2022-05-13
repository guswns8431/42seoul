/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:04:42 by hyson             #+#    #+#             */
/*   Updated: 2022/05/13 16:55:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	this->id_ = 0;
	this->name_ = "NONAME";
	this->grade_ = 0;
}

Data::Data(int id, std::string name, int grade)
{
	this->id_ = id;
	this->name_ = name;
	this->grade_ = grade;
}

Data::Data(const Data& d)
{
	*this = d;
}

Data::~Data(void)
{
}

Data&	Data::operator=(const Data& d)
{
	this->id_ = d.id_;
	this->name_ = d.name_;
	this->grade_ = d.grade_;
	return (*this);
}

int	Data::getID(void) const
{
	return (this->id_);
}

std::string	Data::getName(void) const
{
	return (this->name_);
}

int	Data::getGrade(void) const
{
	return (this->grade_);
}

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
	return (o << "id : "<< d.getID() << std::endl << "name : " << d.getName() << std::endl << "grade : " << d.getGrade() << std::endl);
}

void			print_state(Data* p)
{
	std::cout << "id : " << p->getID() << std::endl;
	std::cout << "name : " << p->getName() << std::endl;
	std::cout << "grade : " << p->getGrade() << std::endl;
}
