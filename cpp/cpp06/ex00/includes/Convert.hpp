/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:40:28 by hyson             #+#    #+#             */
/*   Updated: 2022/05/08 15:45:58 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>
# include <cstring>
# include <cfloat>

class	Convert {
	private:
		std::string input_;
		double		value_;
		std::string	type_;
	public:
		class CanNotDisplayException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class ImpossibleException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		Convert(void);
		Convert(std::string input);
		Convert(const Convert& c);
		~Convert(void);
		Convert&	operator=(const Convert& c);

		char		toChar(void);
		int			toInt(void);
		float		toFloat(void);
		double		toDouble(void);
		void		printChar(void);
		void		printInt(void);
		void		printFloat(void);
		void		printDouble(void);
};

//std::ostream&		operator<<(std::ostream& o, const Convert& c);

#endif
