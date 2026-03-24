# include <iostream>  // to work with console
# include <fstream>   // to work with files
# include <string>    // to work with string
# include <vector>    // to work with massives
# include <algorithm> // required for replace
# include <cstdio>    // required for remove and rename

# include "main.h"   // to work with read.cpp

using namespace std; // to make code easier to write

int redact() {
    char proceed;
    do {
        string filename = "Vocabulary.txt";
        string tmpname = "tmp.txt";
        ifstream file(filename);
        if (!file) {
            cout << "Error: no such file";
            return 1;
        }

        string word_to_redact;
        cout << "Write the word u wanna redact: ";
        cin.ignore();
        getline(cin, word_to_redact);

        string show_line;
        while (getline(file, show_line)) {
            if (show_line.find(word_to_redact) != string::npos) {
                cout << show_line << endl;
            }
        }
        cout << endl;

        file.close();

        string search, replace;
        cout << "Write the word u wanna redact: ";
        getline(cin, search);
        cout << "Write what u wanna print there: ";
        getline(cin, replace);

        ifstream file2(filename);
        ofstream tmp(tmpname);
        string line;
        while (getline(file2, line)) {
            size_t pos = 0;
            while ((pos = line.find(search, pos)) != string::npos) {
                line.replace(pos, search.length(), replace);
                pos += replace.length();
            }
            tmp << line << endl;
        }

        file2.close();
        tmp.close();

        if (remove(filename.c_str()) != 0) {
            cout << "Error with removing original file" << endl;
            return 1;
        }
        if (rename(tmpname.c_str(), filename.c_str()) != 0) {
            cout << "Error renaming temporary file" << endl;
            return 1;
        }

        cout << "Do u wanna continue work [1] | exit [0]: ";
        cin >> proceed;
        if (proceed != '1')
            cout << "Work with file was ended";
    } while (proceed == '1');

    return 0;
}
