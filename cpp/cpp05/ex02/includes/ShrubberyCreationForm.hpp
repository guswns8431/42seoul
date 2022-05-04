/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:30 by hyson             #+#    #+#             */
/*   Updated: 2022/05/04 21:57:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

# define SIGN_GRADE 145
# define EXEC_GRADE 137
# define ASCII_ART_TREE	\
                                                         .		\
                                              .         ;		\
                 .              .              ;%     ;;		\
                   ,           ,                :;%  %;			\
                    :         ;                   :;%;'     .,		\
           ,.        %;     %;            ;        %;'    ,;		\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'		\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'		\
               ;%;      %;        ;%;        % ;%;  ,%;'		\
                `%;.     ;%;     %;'         `;%%;.%;'			\
                 `:;%.    ;%%. %@;        %; ;@%;%'			\
                    `:%;.  :;bd%;          %;@%;'			\
                      `@%:.  :;%.         ;@@%;'			\
                        `@%.  `;@%.      ;@@%;				\
                          `@%%. `@%%    ;@@%;				\
                            ;@%. :@%%  %@@%;				\
                              %@bd%%%bd%%:;				\
                                #@%%%%%:;;				\
                                %@@%%%::;				\
                                %@@@%(o);  . '				\
                                %@@@o%;:(.,'				\
                            `.. %@@@o%::;				\
                               `)@@@o%::;				\
                                %@@(o)::;				\
                               .%@@@@%::;				\
                               ;%@@@@%::;.				\
                              ;%@@@@%%:;;;.				\
                          ...;%@@@@@%%:;;;;,..				

class ShrubberyCreationForm : public form {
	public:
		class	FileOpenError : public std::exceptoin {
			public:
				const char* what(void) const throw();
		};
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& s);
		
		void		execute(Bureaucrat const & executor) const = 0;
};

#endif
