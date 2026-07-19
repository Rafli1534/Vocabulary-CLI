# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <limits>
# include "main.h"

struct Word {
	std::string word;
	std::string translation;
	std::string date;
};

bool existsUA(const std::string& word);
bool existsEN(const std::string& word);

int append() {
	char proceed;
	do 
	{
		std::vector <Word> vocabular;
		std::ofstream file("Vocabulary.txt", std::ios::app);
		if (!file) 
		{
			std::cout << "Error: some problems with file";
			return 1;
		}

		Word data;
		std::cin.ignore(
			std::numeric_limits
			<std::streamsize>
			::max(), 
			'\n'
		); // to clear "cin" data
		std::cout << "Write the word/phrase/ediome in ukrainian: ";
		std::getline(std::cin, data.word);
		std::cout << "Write the translation in english: ";
		std::getline(std::cin, data.translation);
		std::cout << "Write todays date\n"
			<< "(write like dd.MM.yyyy or kinda like this): ";
		std::cin >> data.date;
		vocabular.push_back(data);

		if (existsUA(data.word) && existsEN(data.translation))
			std::cout << "This word already exists" << std::endl;

		else 
		{
			for (auto i : vocabular)
				file << "UA: \""
				<< i.word
				<< "\". EN: \""
				<< i.translation
				<< "\". Date: "
				<< i.date
				<< std::endl;
		}

		file.close();

		std::cout << "Do u wanna continue work "
			<< "with this menu point [1] "
			<< "| exit [0]: ";
		std::cin >> proceed;
		if (proceed != '1') std::cout << "Work with file was ended" << std::endl;

	} 
	while (proceed == '1');

	return 0;
}

bool existsUA(const std::string& word) {
	std::ifstream file("Vocabulary.txt");
	std::string line;
	while (std::getline(file, line))
		if (line.find("UA: \"" + word + "\"") != std::string::npos)
			return true;
	return false;
}

bool existsEN(const std::string& word) {
	std::ifstream file("Vocabulary.txt");
	std::string line;
	while (std::getline(file, line))
		if (line.find("EN: \"" + word + "\"") != std::string::npos)
			return true;
	return false;
}
