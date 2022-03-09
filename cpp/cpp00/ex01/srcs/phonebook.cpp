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
			exit(1);
		else if (cmd == "ADD" || cmd == "add")
		{
			std::cout << "ADD";
			std::cout << "First Name : ";
			pb.C[0].SetInfo(F_N, str);
			pb.C[0].SetInfo(L_N, str);
			pb.C[0].SetInfo(NICK, str);
			pb.C[0].SetInfo(P_N, str);
			pb.C[0].SetInfo(D_S, str);
			std::cout << pb.C[0].GetFirstName() << std::endl;
			std::cout << pb.C[0].GetLastName() << std::endl;
			std::cout << pb.C[0].GetNickname() << std::endl;
			std::cout << pb.C[0].GetPhoneNumber() << std::endl;
			std::cout << pb.C[0].GetDarkestSecret() << std::endl;
		}
		else if (cmd == "SEARCH" || cmd == "search")
		{
			//비어있으면 비어있다고 출력
			std::cout << "SEARCH";
		}
		else
			std::cout << "Invalid Command" << std::endl;
	}
	std::cout << "FINISHED";
}
