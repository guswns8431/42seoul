/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:40:28 by hyson             #+#    #+#             */
/*   Updated: 2022/05/06 21:56:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

class	Convert {
	private:
		std::string input_;
	public:
		Convert(void);
		Convert(std::string input);
		Convert(const Convert& c);
		~Convert(void);
		Convert&	operator=(const Convert& c);

		char		toChar(void);
		int			toInt(void);
		float		toFloat(void);
		double		toDouble(void);
};

std::ostream&		operator<<(std::ostream& o, const Convert& c);

#endif
