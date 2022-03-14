#include "phonebook.hpp"

int main(void)
{
	std::string cmd;
	std::string str;
	PhoneBook pb;

	std::cout << "Type the Command EXIT / ADD / SEARCH" << std::endl;
	while(std::getline(std::cin, cmd))
	{
		if (cmd == "EXIT" || cmd == "exit")
			return (0);
		else if (cmd == "ADD" || cmd == "add")
			pb.ContactAdd();
		else if (cmd == "SEARCH" || cmd == "search")
		{
			//비어있으면 비어있다고 출력
			//ctrl + c 처
			pb.PrintPhoneBook(); //전화번호부가 비어있을때도 처리해줘야함
		}
		else
			std::cout << "Invalid Command" << std::endl;
	}
}
