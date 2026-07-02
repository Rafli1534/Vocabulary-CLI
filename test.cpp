# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <chrono>

# include "main.h"

void game() 
{
    srand(time(nullptr));
    std::ifstream file("Vocabulary.txt");
    if (!file) 
    {
        std::cout << "Error: no such file";
        return;
    }

    std::string line;
    std::vector<std::string> entries;
    std::cin.ignore();
    while (std::getline(file, line))
        if (!line.empty())
            entries.push_back(line);

    file.close();

    if (entries.empty()) 
    {
        std::cout << "No words found!";
        return;
    }

    int amount;
    std::cout << "How many words u wanna test: ";
    std::cin >> amount;

    int correct = 0, wrong = 0;
    auto startPlayer = std::chrono::steady_clock::now();

    for (int i = 0; i < amount; ++i) 
    {
        int randin = rand() % entries.size();
        std::string entry = entries[randin];

        size_t posUA = entry.find("UA:");
        size_t endUA = entry.find('.', posUA);
        std::string uaWord = entry.substr(posUA, endUA - posUA);

        std::cout << "\nTranslate this word -> " << uaWord << std::endl;
        std::string answer;
        bool ok = false;
        while (!ok) 
        {
            std::cout << "Your translation: ";
            std::cin.ignore();
            std::getline(std::cin, answer);

            if (entry.find(answer) != std::string::npos) 
            {
                std::cout << "Correct!\n";
                correct++;
                ok = true;
            }
            else 
            {
                std::cout << "Wrong, try again!\n";
                wrong++;
            }
        }
    }

    auto endPlayer = std::chrono::steady_clock::now();//закінчення часу
    std::chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
    double timePlayer = elapsedPlayer.count();

    std::cout << "\nGame over!\n";
    std::cout << "Correct answers: " << correct << std::endl;
    std::cout << "Wrong attempts: " << wrong << std::endl;
    std::cout << "Timer user: " << timePlayer << " sec." << std::endl;
}

int test() 
{
    std::cin.ignore();
	char proceed;
	do 
    {
		char ready;
        std::cout << "\033[2J\033[1;1H"; // screen cleaning
        std::cout << "Hi! It will be like a game\n"
            << "U'll have a timer, u'll know\n"
            << "how much mistakes and correct\n"
            << "answers u've given.\n" << std::endl;
		
        game();

        std::cout << "Do u wanna continue work "
			<< "with this menu point [1] "
			<< "| exit [0]: ";
        std::cin >> proceed;

		if (proceed != '1') std::cout << "Work with file was ended";
	} 
    while (proceed == '1');

	return 0;
}
