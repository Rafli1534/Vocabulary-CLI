# include <iostream>  // to work with console
# include <fstream>   // to work with files
# include <string>    // to work with string
# include <vector>    // to work with massives
# include <algorithm> // required for replace
# include <cstdio>    // required for remove and rename

# include "main.h"   // to work with read.cpp

int redact() 
{
    char proceed;
    do 
    {
        std::string filename = "Vocabulary.txt";
        std::string tmpname = "tmp.txt";
        std::ifstream file(filename);
        if (!file) 
        {
            std::cout << "Error: no such file";
            return 1;
        }

        std::string word_to_redact;
        std::cout << "Write the word u wanna redact: ";
        std::cin.ignore();
        std::getline(std::cin, word_to_redact);

        std::string show_line;
        while (std::getline(file, show_line)) 
            if (show_line.find(word_to_redact) != std::string::npos) 
                std::cout << show_line << std::endl;
        std::cout << std::endl;

        file.close();

        std::string search, replace;
        std::cout << "Write the word u wanna redact: ";
        std::getline(std::cin, search);
        std::cout << "Write what u wanna print there: ";
        std::getline(std::cin, replace);

        std::ifstream file2(filename);
        std::ofstream tmp(tmpname);
        std::string line;
        while (std::getline(file2, line)) 
        {
            size_t pos = 0;
            while ((pos = line.find(search, pos)) != std::string::npos) 
            {
                line.replace(pos, search.length(), replace);
                pos += replace.length();
            }
            tmp << line << std::endl;
        }

        file2.close();
        tmp.close();

        if (remove(filename.c_str()) != 0) 
        {
            std::cout << "Error with removing original file" << std::endl;
            return 1;
        }

        if (rename(tmpname.c_str(), filename.c_str()) != 0) 
        {
            std::cout << "Error renaming temporary file" << std::endl;
            return 1;
        }

        std::cout << "Do u wanna continue work [1] | exit [0]: ";
        std::cin >> proceed;
        if (proceed != '1') std::cout << "Work with file was ended";
    } 
    while (proceed == '1');

    return 0;
}
