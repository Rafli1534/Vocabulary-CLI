# include <iostream>
# include <fstream>
# include <string>
# include <cstdio>
# include <limits>
# include "main.h"

int del()
{
    char proceed;
    do 
    {
        std::string filename = "Vocabulary.txt";
        std::ifstream input(filename);
        std::ofstream temp("temp.txt");
        std::string line;

        if (!input || !temp) 
        {
            std::cout << "Error: no such file" << std::endl;
            return 1;
        }

        std::string word;
        std::cout << "Write word u wanna remove: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, word);

        bool found = false;
        while (getline(input, line)) {
            if (line.find(word) == std::string::npos) {
                temp << line << std::endl;
            }
            else {
                found = true;
            }
        }

        input.close();
        temp.close();

        if (!found) 
        {
            std::cout << "Word not found in file" << std::endl;
            remove("temp.txt");
        }
        else 
        {
            if (remove(filename.c_str()) != 0) 
            {
                std::cout << "Error removing original file: " << filename << std::endl;
                return 1;
            }
            if (rename("temp.txt", filename.c_str()) != 0) 
            {
                std::cout << "Error renaming temp file" << std::endl;
                return 1;
            }
            std::cout << "Word removed successfully" << std::endl;
        }

        std::cout << "Do u wanna continue work with this menu point [1] | exit [0]: ";
        std::cin >> proceed;
        if (proceed != '1') std::cout << "Work with file was ended" << std::endl;

    } 
    while (proceed == '1');

    return 0;
}