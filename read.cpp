# include <iostream> // to work with console
# include <fstream>  // to work with files
# include <string>   // to work with string
# include <vector>   // to work with massives
# include "main.h"   // to work with the main.cpp

using namespace std;

int read() {
	char proceed;
	do {
		ifstream file("Vocabulary.txt"); // opening file for reading

		if (!file) {
			cout << "Error: no such file";
			return 1;
		} // test is there a file

		string text;

		while (getline(file, text)) {
			cout << text << endl;
		} // printing file data

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