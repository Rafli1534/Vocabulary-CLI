# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <chrono>

# include "main.h"

using namespace std;

void game() {
    srand(time(nullptr));
    ifstream file("Vocabulary.txt");
    if (!file) {
        cout << "Error: no such file";
        return;
    }

    string line;
    vector<string> entries;
    cin.ignore();
    while (getline(file, line))
        if (!line.empty())
            entries.push_back(line);

    file.close();

    if (entries.empty()) {
        cout << "No words found!";
        return;
    }

    int amount;
    cout << "How many words u wanna test: ";
    cin >> amount;

    int correct = 0, wrong = 0;
    auto startPlayer = chrono::steady_clock::now();

    for (int i = 0; i < amount; ++i) {
        int randin = rand() % entries.size();
        string entry = entries[randin]; 

        size_t posUA = entry.find("UA:");
        size_t endUA = entry.find('.', posUA);
        string uaWord = entry.substr(posUA, endUA - posUA);

        cout << "\nTranslate this word -> " << uaWord << endl;
        string answer;
        bool ok = false;
        while (!ok) {
            cout << "Your translation: ";
            cin.ignore();
            getline(cin, answer);

            if (entry.find(answer) != string::npos) {
                cout << "Correct!\n";
                correct++;
                ok = true;
            }
            else {
                cout << "Wrong, try again!\n";
                wrong++;
            }
        }
    }

    auto endPlayer = chrono::steady_clock::now();//закінчення часу
    chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
    double timePlayer = elapsedPlayer.count();

    cout << "\nGame over!\n";
    cout << "Correct answers: " << correct << endl;
    cout << "Wrong attempts: " << wrong << endl;
    cout << "Timer user: " << timePlayer << " sec." << endl;
}

int test() {
    cin.ignore();
	char proceed;
	do {
		char ready;
		cout << "\033[2J\033[1;1H"; // screen cleaning
        cout << "Hi! It will be like a game\n"
            << "U'll have a timer, u'll know\n"
            << "how much mistakes and correct\n"
            << "answers u've given.\n" << endl;
		
        game();

		cout << "Do u wanna continue work "
			<< "with this menu point [1] "
			<< "| exit [0]: ";
		cin >> proceed;

		if (proceed != '1')
			cout << "Work with file was ended";
	} while (proceed == '1');

	return 0;
}
