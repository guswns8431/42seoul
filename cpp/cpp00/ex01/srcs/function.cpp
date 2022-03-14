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

void		Contact::SetInfo(int type, std::string field)
{
	std::string str;

	std::cout << field;
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

void		PhoneBook::ContactAdd(void)
{
	if (this->size_ < 8)
		++this->size_;
	if (is_overwrite_)
		std::cout << "Index [ " << RED << this->i_ << EOC << " / " << this->size_ << " ] " << std::endl;
	else
		std::cout << "Index [ " << this->i_ << " / " << this->size_ << " ] " << std::endl;
	this->C[this->i_ - 1].SetInfo(F_N, "First Name : ");
	this->C[this->i_ - 1].SetInfo(L_N, "Last Name : ");
	this->C[this->i_ - 1].SetInfo(NICK, "Nickname : ");
	this->C[this->i_ - 1].SetInfo(P_N, "Phone Number : ");
	this->C[this->i_ - 1].SetInfo(D_S, "Darkest Secret : ");
	this->i_ = ++this->i_ % 9;
	if (this->i_ == 0)
	{
		this->i_ = 1;
		is_overwrite_ = true;
	}
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

void		PhoneBook::PrintPhoneBook(void)
{
	int i = 0;

	if (this->size_ == 0)
	{
		std::cout << "PhoneBook is "<< GREEN << "Empty" << EOC << std::endl;
		return ;
	}
	std::cout << std::setfill(' ') << std::setw(COL_WIDTH) << "Index" << "|"
		<< std::setfill(' ') << std::setw(COL_WIDTH) << "First Name" << "|"
		<< std::setfill(' ') << std::setw(COL_WIDTH) << "Last Name" << "|"
		<< std::setfill(' ') << std::setw(COL_WIDTH) << "Nickname" << "|"
		<< std::endl;
	while (++i <= this->size_)
	{
		//정렬. setw랑 setfill을 잘 써야할듯
		//디테일 뽑는 함수
		std::cout << std::setfill(' ') << std::setw(COL_WIDTH) << i << "|"
			<< std::setfill(' ') << std::setw(COL_WIDTH) << CutInfo(this->C[i - 1].GetFirstName()) << "|"
			<< std::setfill(' ') << std::setw(COL_WIDTH) << CutInfo(this->C[i - 1].GetLastName()) << "|"
			<< std::setfill(' ') << std::setw(COL_WIDTH) << CutInfo(this->C[i - 1].GetNickname()) << "|"
			<< std::endl;
	}
}
