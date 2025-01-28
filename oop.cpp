#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// Hangman class for encapsulating game logic
class Hangman {
private:
    static const int MAX_TRIES = 6;
    string secretWord;
    string hint;
    vector<bool> guessedLetters;
    int tries;

    // Helper function to read a random word and hint from the file
    void readWordAndHintFromFile() {
        ifstream file("words.txt");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            exit(1);
        }

        vector<string> lines;
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();

        if (lines.empty()) {
            cerr << "No words found in file!" << endl;
            exit(1);
        }

        srand(time(nullptr));
        int randomIndex = rand() % lines.size();

        // Split the line into word and hint
        size_t commaPos = lines[randomIndex].find(',');
        if (commaPos != string::npos) {
            secretWord = lines[randomIndex].substr(0, commaPos);
            hint = lines[randomIndex].substr(commaPos + 1);
        } else {
            cerr << "Invalid file format!" << endl;
            exit(1);
        }

        guessedLetters.resize(26, false); // Initialize guessed letters
    }

    // Function to display the current state of the word
    void displayWord() const {
        for (char c : secretWord) {
            if (guessedLetters[tolower(c) - 'a']) {
                cout << c << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }

    // Function to draw the hangman figure
    void drawHangman() const {
        const vector<string> hangmanParts = {
            "     _________",
            "    |         |",
            "    |         O",
            "    |        /|\\",
            "    |        / \\",
            "    |"
        };

        for (int i = 0; i <= tries && i < hangmanParts.size(); i++) {
            cout << hangmanParts[i] << endl;
        }
    }

    // Check if the word is fully guessed
    bool isWordGuessed() const {
        for (char c : secretWord) {
            if (!guessedLetters[tolower(c) - 'a']) {
                return false;
            }
        }
        return true;
    }

public:
    Hangman() : tries(0) {
        readWordAndHintFromFile();
    }

    void play() {
        cout << "Welcome to Hangman!" << endl;
        cout << "Hint: " << hint << endl;

        while (tries < MAX_TRIES) {
            cout << endl;
            displayWord();
            drawHangman();

            char guess;
            cout << "Enter a letter: ";
            cin >> guess;
            guess = tolower(guess);

            // Check if the letter has already been guessed
            if (guessedLetters[guess - 'a']) {
                cout << "You've already guessed that letter. Try again." << endl;
                continue;
            }

            guessedLetters[guess - 'a'] = true;

            // Check if the guessed letter is in the word
            bool found = false;
            for (char c : secretWord) {
                if (tolower(c) == guess) {
                    found = true;
                }
            }

            if (!found) {
                tries++;
                cout << "Incorrect guess!" << endl;
            }

            if (isWordGuessed()) {
                cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
                return;
            }
        }

        cout << "\nSorry, you've run out of tries. The word was: " << secretWord << endl;
    }
};

// Main function to control the game flow
int main() {
    Hangman game;
    game.play();
    return 0;
}
