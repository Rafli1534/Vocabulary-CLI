# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>

# include "read.h"
# include "append.h"
# include "search.h"
# include "del.h"
# include "redact.h"
# include "test.h"

using namespace std;

int main()
{
	system("chcp 65001>null"); 
	char choice;
	do {
		cout << "Menu: \n"
			<< "\t1. Read Vocabulary\n"
			<< "\t2. Append some info\n"
			<< "\t3. Search\n"
			<< "\t4. Delete\n"
			<< "\t5. Redact\n"
			<< "\t6. Test ur knowledge\n"
			<< "\t0. Exit program\n"
			<< "Your choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
			case '0': break;
			case '1': read(); break;
			case '2': append(); break;
			case '3': search(); break;
   case '4': del(); break;
			case '5': redact(); break;
			case '6': test(); break;
			default:
				cout << "Error: no such variant";
				return 1;
				break;
		}

		if (choice > '0' && choice <= '6') 
			cout << "\033[2J\033[1;1H"; // screen cleaning
	} while (choice > '0' && choice <= '6');
	cout << "\033[0m";
	return 0;
}
