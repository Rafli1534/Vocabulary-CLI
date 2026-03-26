# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include "main.h"
using namespace std;

int read() {
	char proceed;
	do {
		ifstream file("Vocabulary.txt");

		if (!file) {
			cout << "Error: no such file";
			return 1;
		}

		string text;

		while (getline(file, text))
			cout << text << endl;

		file.close();

		cout << "Do u wanna continue work "
			<< "with this menu point [1] "
			<< "| exit [0]: ";
		cin >> proceed;
		if (proceed != '1')
			cout << "Work with file was ended";
	} while (proceed == '1');

	return 0;
}