/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:30 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 17:07:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

# define S_SIGN_GRADE 145
# define S_EXEC_GRADE 137
# define ASCII_ART_TREE	"\n\
                                                         .		\n\
                                              .         ;		\n\
                 .              .              ;%     ;;		\n\
                   ,           ,                :;%  %;			\n\
                    :         ;                   :;%;'     .,		\n\
           ,.        %;     %;            ;        %;'    ,;		\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'		\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'		\n\
               ;%;      %;        ;%;        % ;%;  ,%;'		\n\
                `%;.     ;%;     %;'         `;%%;.%;'			\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'			\n\
                    `:%;.  :;bd%;          %;@%;'			\n\
                      `@%:.  :;%.         ;@@%;'			\n\
                        `@%.  `;@%.      ;@@%;				\n\
                          `@%%. `@%%    ;@@%;				\n\
                            ;@%. :@%%  %@@%;				\n\
                              %@bd%%%bd%%:;				\n\
                                #@%%%%%:;;				\n\
                                %@@%%%::;				\n\
                                %@@@%(o);  . '				\n\
                                %@@@o%;:(.,'				\n\
                            `.. %@@@o%::;				\n\
                               `)@@@o%::;				\n\
                                %@@(o)::;				\n\
                               .%@@@@%::;				\n\
                               ;%@@@@%::;.				\n\
                              ;%@@@@%%:;;;.				\n\
                          ...;%@@@@@%%:;;;;,.."

class ShrubberyCreationForm : public Form {
	public:
		class	FileOpenError : public std::exception {
			public:
				const char* what(void) const throw();
		};
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& s);

		void		execute(Bureaucrat const & executor) const;
};

#endif
