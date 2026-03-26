# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include "main.h"

using namespace std; 

struct Word {
	string word;
	string translation;
	string date;
};

bool existsUA(const string& word);
bool existsEN(const string& word);

int append() {
	char proceed;
	do {
		vector <Word> vocabular;
		ofstream file("Vocabulary.txt", ios::app);
		if (!file) {
			cout << "Error: some problems with file";
			return 1;
		}

		Word data;
		cin.ignore(
			numeric_limits
			<streamsize>
			::max(), 
			'\n'
		); // to clear "cin" data
		cout << "Write the word/phrase/ediome in ukrainian: ";
		getline(cin, data.word);
		cout << "Write the translation in english: ";
		getline(cin, data.translation);
		cout << "Write todays date\n"
			<< "(write like dd.MM.yyyy or kinda like this): ";
		cin >> data.date;
		vocabular.push_back(data);

		if (existsUA(data.word) && existsEN(data.translation))
			cout << "This word already exists" << endl;

		else {
			for (auto i : vocabular)
				file << "UA: \""
				<< i.word
				<< "\". EN: \""
				<< i.translation
				<< "\". Date: "
				<< i.date
				<< endl;
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

bool existsUA(const string& word) {
	ifstream file("Vocabulary.txt");
	string line;
	while (getline(file, line))
		if (line.find("UA: \"" + word + "\"") != string::npos)
			return true;
	return false;
}

bool existsEN(const string& word) {
	ifstream file("Vocabulary.txt");
	string line;
	while (getline(file, line))
		if (line.find("EN: \"" + word + "\"") != string::npos)
			return true;
	return false;
}