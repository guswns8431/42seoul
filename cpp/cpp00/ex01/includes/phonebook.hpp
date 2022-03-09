#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

# define F_N	0
# define L_N	1
# define NICK	2
# define P_N	3
# define D_S	4 

class Contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		std::string	GetFirstName(void) {
			return (this->first_name_);
		}
		std::string	GetLastName(void) {
			return (this->last_name_);
		}
		std::string	GetNickname(void) {
			return (this->nickname_);
		}
		std::string	GetPhoneNumber(void) {
			return (this->phone_number_);
		}
		std::string	GetDarkestSecret(void) {
			return (this->darkest_secret_);
		}
		void		SetInfo(int type, std::string str) {
			if (!std::getline(std::cin, str))
				exit(1);
			if (type == F_N)
				this->first_name_ = str;
			else if (type == L_N)
				this->last_name_ = str;
			else if (type == NICK)
				this->nickname_ = str;
			else if (type == P_N)
				this->phone_number_ = str;
			else
				this->darkest_secret_ = str;
		}
};

class PhoneBook {
	public:
		Contact C[8];
};

#endif
