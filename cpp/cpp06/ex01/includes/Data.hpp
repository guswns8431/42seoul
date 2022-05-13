/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:57:42 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 08:09:19 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct	Data {
		int 		id_;
		std::string name_;
		int 		grade_;
};

uintptr_t		serialize(Data* ptr);
Data*			deserialize(uintptr_t raw);
std::ostream&	operator<<(std::ostream& o, const Data& ptr);
void			print_state(Data* p);

#endif
