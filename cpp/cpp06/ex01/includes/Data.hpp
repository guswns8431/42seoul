/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:57:42 by hyson             #+#    #+#             */
/*   Updated: 2022/05/13 16:54:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class	Data {
	private:
		int id_;
		std::string name_;
		int grade_;
	public:
		Data(void);
		Data(int id, std::string name, int grade);
		Data(const Data& d);
		~Data(void);
		Data&	operator=(const Data& d);

		int	getID(void) const;
		std::string	getName(void) const;
		int	getGrade(void) const;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
std::ostream&	operator<<(std::ostream& o, const Data& ptr);
void			print_state(Data* p);

#endif
