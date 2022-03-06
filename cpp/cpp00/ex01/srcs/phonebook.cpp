#include <iostream>
#include <string>

int main(void)
{
	std::string cmd;

	std::cout << "Type the Command EXIT / ADD / SEARCH" << std::endl;
	while(std::getline(std::cin, cmd))
	{
		if (cmd == "EXIT" || cmd == "exit")
			exit(1);
		else if (cmd == "ADD" || cmd == "add")
			std::cout << "ADD";
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
