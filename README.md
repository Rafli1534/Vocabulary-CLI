# Vocabulary CLI

## 📜Description:
A console application written in C++ for managing a vocabulary file and testing knowledge.
The program provides the following features:
- Read the vocabulary file,
- Append new entries,
- Search for words,
- Delete entries,
- Edit existing entries,
- Play a mini‑game to test translations.

### 📋Requirements:
- C++ 20 or newer,
- Any compiler (g++, clang, MSVC),
- A file named Vocabulary.txt with entries in the format:

`UA: "Око". EN: "Eye". Date: 22.03.2026`.

`UA: "Сонце". EN: "Sun". Date: 22.03.2026`.

### 🏃‍➡️Build and run:
Compile the project:
`g++ main.cpp read.cpp append.cpp search.cpp del.cpp redact.cpp test.cpp -o [file_name]`.

And run the executable:
`./[file_name]`.

## 🧪Example Usage
    Menu:
        1. Read Vocabulary
        2. Append some info
        3. Search
        4. Delete
        5. Redact
        6. Test your knowledge
        0. Exit program
    Your choice: 6

    Translate this word -> UA: "Око"
    Your translation: Eye
    Correct!

    Game over!
    Correct answers: 1
    Wrong attempts: 0
    Timer user: 5.3 sec.

## 🏗️Project Structure
- `main.cpp` — entry point, implements the menu.
- `read.cpp` — reads and prints the vocabulary file.
- `append.cpp` — adds new words with translation and date, checks for duplicates.
- `search.cpp` — searches for words in the file and prints matching lines.
- `del.cpp` — deletes words by rewriting the file without them.
- `redact.cpp` — edits words by replacing them with new values.
- `test.cpp` — mini‑game: asks for translations, counts correct/incorrect answers, measures time.


## 💪Features:
- Manage vocabulary in a text file
- Add, search, delete, and edit entries
- Play a translation quiz game
- Track correct and incorrect answers
- Measure time spent in the game

#### made by null (or nullptr?)
