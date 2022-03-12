#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define F_N		0
# define L_N		1
# define NICK		2
# define P_N		3
# define D_S		4 

# define COL_WIDTH	10

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define EOC		"\033[0;0m"

class Contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickname(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);
		void		SetInfo(int type, std::string field);
};

class PhoneBook {
	private:
		bool	is_overwrite_;
		int	i_;
		int	size_;
		Contact C[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	ContactAdd(void);
		std::string	CutInfo(std::string str);
		void	PrintPhoneBook(void);
};

#endif
