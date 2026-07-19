# include <iostream>
# include <cstdlib>

# include "read.h"
# include "append.h"
# include "search.h"
# include "del.h"
# include "redact.h"
# include "test.h"

void printMainMenu()
{
	std::cout << "Menu: \n"
		<< "\t1. Read Vocabulary\n"
		<< "\t2. Append some info\n"
		<< "\t3. Search\n"
		<< "\t4. Delete\n"
		<< "\t5. Redact\n"
		<< "\t6. Test ur knowledge\n"
		<< "\t0. Exit program\n"
		<< "Your choice: ";
}

void keepMenuCHoice(char choice)
{
	switch (choice) 
	{
		case '0': break;
		case '1': read(); break;
		case '2': append(); break;
		case '3': search(); break;
		case '4': del(); break;
		case '5': redact(); break;
		case '6': test(); break;
		default:
			std::cout << "Error: no such variant";
			return;
			break;
	}

	if (choice > '0' && choice <= '6') std::cout << "\033[2J\033[1;1H"; // screen cleaning
}

int main()
{
	std::system("chcp 65001>null"); 
	char choice;
	do 
	{
		printMainMenu();
		std::cin >> choice;
		std::cout << std::endl;
		keepMenuCHoice(choice);
	} 
	while (choice > '0' && choice <= '6');
	std::cout << "\033[0m";
	return 0;
}
