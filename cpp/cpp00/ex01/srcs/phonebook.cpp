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
		{
			std::cout << "ADD";
			/*
			pb.C[0].SetInfo(F_N, str, "First Name : ");
			pb.C[0].SetInfo(L_N, str, "Last Name : ");
			pb.C[0].SetInfo(NICK, str, "Nickname : ");
			pb.C[0].SetInfo(P_N, str, "Phone Number : ");
			pb.C[0].SetInfo(D_S, str, "Darkest Secret : ");
			
			std::cout << pb.C[0].GetFirstName() << std::endl;
			std::cout << pb.C[0].GetLastName() << std::endl;
			std::cout << pb.C[0].GetNickname() << std::endl;
			std::cout << pb.C[0].GetPhoneNumber() << std::endl;
			std::cout << pb.C[0].GetDarkestSecret() << std::endl;
			*/
			pb.ContactAdd();
		}
		else if (cmd == "SEARCH" || cmd == "search")
		{
			//비어있으면 비어있다고 출력
			//ctrl + c 처
			std::cout << "SEARCH" << std::endl;
			pb.PrintPhoneBook(); //전화번호부가 비어있을때도 처리해줘야함
		}
		else
			std::cout << "Invalid Command" << std::endl;
	}
	std::cout << "test";
}
