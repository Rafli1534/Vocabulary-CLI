# include <iostream> // to work with console
# include <fstream>  // to work with files
# include <string>   // to work with string
# include <vector>   // to work with massives

# include "main.h"   // to work with read.cpp

using namespace std; // to make code easier to write

int search() {
	char proceed;
	do {
		ifstream file("Vocabulary.txt");
		if (!file) {
			cout << "Error: no such file";
			return 1;
		}

		string word_to_find;
		string line;

		cout << "Write the word u wanna find: ";
		cin.ignore();
		getline(cin, word_to_find);

		while (getline(file, line)) {
			if (line.find(word_to_find) != string::npos) {
				cout << line << endl;
			}
		}
		
		file.close();
		cout << "Do u wanna continue work "
			<< "with this menu point [1] "
			<< "| exit [0]: ";
		cin >> proceed;
		if (proceed != '1')
			cout << "Work with file was ended" << endl;

	} while (proceed == '1');

	return 0;
}