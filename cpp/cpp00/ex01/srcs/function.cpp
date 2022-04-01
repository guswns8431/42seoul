#include "phonebook.hpp"

std::string	Contact::GetFirstName(void)
{
	return (this->first_name_);
}

std::string	Contact::GetLastName(void)
{
	return (this->last_name_);
}

std::string	Contact::GetNickname(void)
{
	return (this->nickname_);
}

std::string	Contact::GetPhoneNumber(void)
{
	return (this->phone_number_);
}

std::string	Contact::GetDarkestSecret(void)
{
	return (this->darkest_secret_);
}

bool		Contact::SetInfo(int type, std::string field)
{
	std::string str;

	std::cout << field;
	if (!std::getline(std::cin, str))
		return (false);
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
	return (true);
}

PhoneBook::PhoneBook(void)
{
	this->is_overwrite_ = false;
	this->size_ = 0;
	this->i_ = 1;
	std::cout << std::endl;
	std::cout << YELLOW << "PhoneBook" << EOC << " is " << GREEN << "created" << EOC << " successfully" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << std::endl;
	std::cout << YELLOW << "PhoneBook" << EOC << " is " << RED << "deleted" << EOC << " successfully" << std::endl;
}

bool		PhoneBook::ContactAdd(void)
{
	if (this->size_ < 8)
		++this->size_;
	std::cout << std::endl;
	if (is_overwrite_)
		std::cout << "Index [ " << RED << this->i_ << EOC << " / " << this->size_ << " ] " << std::endl;
	else
		std::cout << "Index [ " << this->i_ << " / " << this->size_ << " ] " << std::endl;
	if (!this->C[this->i_ - 1].SetInfo(F_N, "First Name : ")
		|| !this->C[this->i_ - 1].SetInfo(L_N, "Last Name : ")
		|| !this->C[this->i_ - 1].SetInfo(NICK, "Nickname : ")
		|| !this->C[this->i_ - 1].SetInfo(P_N, "Phone Number : ")
		|| !this->C[this->i_ - 1].SetInfo(D_S, "Darkest Secret : "))
		return (false);
	this->i_ = ++this->i_ % 9;
	if (this->i_ == 0)
	{
		this->i_ = 1;
		is_overwrite_ = true;
	}
	return (true);
}

std::string	PhoneBook::CutInfo(std::string str)
{
	if (str.size() > COL_WIDTH)
	{
		str[COL_WIDTH - 1] = '.';
		str.erase(COL_WIDTH);
	}
	return (str);
}

int		PhoneBook::PrintDetail(int contact_size)
{
	std::string 	input;
	int		i;

	std::cout << BLUE << "Type" << EOC << " Index Number(0 to Exit) : ";
	if (!std::getline(std::cin, input))
		return (TERM);
	if (input == "0")
		return (VALID);
	i = atoi(input.c_str());
	if (i > contact_size || i < 1)
	{
		std::cout << std::endl;
		std::cout << RED << "Wrong" << EOC << " Index. " << BLUE << "Check" << EOC << " Index Number" << std::endl;
		return (WRONGINDEX);
	}
	std::cout << std::endl;
	std::cout << "1. First Name : " << C[i - 1].GetFirstName() << std::endl;
	std::cout << "2. Last Name : " << C[i - 1].GetLastName() << std::endl;
	std::cout << "3. Nickname : " << C[i - 1].GetNickname() << std::endl;
	std::cout << "4. Phone Number : " << C[i - 1].GetPhoneNumber() << std::endl;
	std::cout << "5. Darkest Secret : " << C[i - 1].GetDarkestSecret() << std::endl;
	std::cout << std::endl;
	return (VALID);
}

bool		PhoneBook::PrintPhoneBook(void)
{
	int i;
	int res = 0;

	if (this->size_ == 0)
	{
		std::cout << std::endl;
		std::cout << YELLOW << "PhoneBook" << EOC << " is "<< GREEN << "Empty" << EOC << std::endl;
		return (true);
	}
	while (true)
	{
		i = 0;
		std::cout << std::endl;
		std::cout << std::setfill(' ') << std::setw(COL_WIDTH) << "Index" << "|"
			<< std::setfill(' ') << std::setw(COL_WIDTH) << "First Name" << "|"
			<< std::setfill(' ') << std::setw(COL_WIDTH) << "Last Name" << "|"
			<< std::setfill(' ') << std::setw(COL_WIDTH) << "Nickname" << "|"
			<< std::endl;
		while (++i <= this->size_)
		{
			std::cout << std::setfill(' ') << std::setw(COL_WIDTH) << i << "|"
				<< std::setfill(' ') << std::setw(COL_WIDTH) << CutInfo(this->C[i - 1].GetFirstName()) << "|"
				<< std::setfill(' ') << std::setw(COL_WIDTH) << CutInfo(this->C[i - 1].GetLastName()) << "|"
				<< std::setfill(' ') << std::setw(COL_WIDTH) << CutInfo(this->C[i - 1].GetNickname()) << "|"
				<< std::endl;
		}
		res = PrintDetail(this->size_);
		if (res == 0)
			return (false);
		else if (res == 1)
			continue ;
		else
			break ;
	}
	return (true);
}
