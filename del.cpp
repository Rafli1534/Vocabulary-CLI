# include <iostream> // to work with console
# include <fstream>  // to work with files
# include <string>   // to work with string
# include <cstdio>   // for remove() and rename()
# include "main.h"   // to work with the main.cpp

using namespace std;

int del() {
    char proceed;
    do {
        string filename = "Vocabulary.txt";
        ifstream input(filename);
        ofstream temp("temp.txt");
        string line;

        if (!input || !temp) {
            cout << "Error: no such file" << endl;
            return 1;
        }

        string word;
        cout << "Write word u wanna remove: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, word);

        bool found = false;
        while (getline(input, line)) {
            if (line.find(word) == string::npos)
                temp << line << endl;
            else found = true;
        }

        input.close();
        temp.close();

        if (!found) {
            cout << "Word not found in file" << endl;
            remove("temp.txt");
        }
        else {
            if (remove(filename.c_str()) != 0) {
                cout << "Error removing original file: " << filename << endl;
                return 1;
            }
            if (rename("temp.txt", filename.c_str()) != 0) {
                cout << "Error renaming temp file" << endl;
                return 1;
            }
            cout << "Word removed successfully" << endl;
        }

        cout << "Do u wanna continue work with this menu point [1] | exit [0]: ";
        cin >> proceed;
        if (proceed != '1')
            cout << "Work with file was ended" << endl;

    } while (proceed == '1');

    return 0;
}