/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mimes.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:47:01 by hyson             #+#    #+#             */
/*   Updated: 2022/08/17 18:50:14 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIMES_HPP
# define MIMES_HPP

# include <string>

# include "./Utilizer.hpp"

class Mimes
{
private:
	MimeMapper _mapper;

	Mimes(const Mimes &m);
	Mimes &operator=(const Mimes &m);

public:
	Mimes(void);
	~Mimes(void);

	const std::string &get_type(const std::string &extension);
};

#endif
