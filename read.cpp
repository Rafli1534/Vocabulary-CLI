# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include "main.h"

int read() 
{
	char proceed;
	do 
	{
		std::ifstream file("Vocabulary.txt");
		if (!file) 
		{
			std::cout << "Error: no such file";
			return 1;
		}

		std::string text;

		while (std::getline(file, text))
			std::cout << text << std::endl;

		file.close();

		std::cout << "Do u wanna continue work "
			<< "with this menu point [1] "
			<< "| exit [0]: ";
		std::cin >> proceed;
		if (proceed != '1')
			std::cout << "Work with file was ended";
	} 
	while (proceed == '1');

	return 0;
}