#include "phonebook.hpp"

int main(void)
{
	std::string cmd;
	std::string str;
	PhoneBook pb;

	std::cout << std::endl;
	std::cout << BLUE << "Type" << EOC
		<< " the Command( "
		<< BLUE << "EXIT" << EOC
		<< " or "
		<< BLUE << "ADD" << EOC
		<< " or "
		<< BLUE << "SEARCH" << EOC
		<< " )"
		<< std::endl;
	while(std::getline(std::cin, cmd))
	{
		if (cmd == "EXIT" || cmd == "exit")
			return (0);
		else if (cmd == "ADD" || cmd == "add")
			pb.ContactAdd();
		else if (cmd == "SEARCH" || cmd == "search")
		{
			if(!pb.PrintPhoneBook())
				return (0);
		}
		else
		{
			std::cout << RED << "Invalid" << EOC << " Command" << std::endl;
			continue ;
		}
		std::cout << std::endl;
		std::cout << BLUE << "Type" << EOC
			<< " the Command( "
			<< BLUE << "EXIT" << EOC
			<< " or "
			<< BLUE << "ADD" << EOC
			<< " or "
			<< BLUE << "SEARCH" << EOC
			<< " )"
			<< std::endl;
	}
	return (0);
}
