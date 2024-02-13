#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    const int MAX_WRONG_ATTEMPTS = 7;
    std::vector<std::string> words;
    words.push_back("HELLO");
    words.push_back("WORLD");
    words.push_back("COMPUTER");
    words.push_back("PROGRAMMING");
    words.push_back("HANGMAN");

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    char playAgain;
    do {
        std::string secretWord = words[std::rand() % words.size()];
        std::string guessedLetters(secretWord.length(), '_');

        int wrongAttempts = 0;
        std::string usedLetters = "";

        std::cout << "*** Hangman Game ***\n\n";
        
        while (wrongAttempts < MAX_WRONG_ATTEMPTS && guessedLetters != secretWord) {
            std::cout << "Guess the word: " << guessedLetters << "\n";
            std::cout << "Used letters: " << usedLetters << "\n";

            char guess;
            std::cout << "Enter a letter: ";
            std::cin >> guess;
            guess = toupper(guess);

            if (usedLetters.find(guess) != std::string::npos) {
                std::cout << "You've already guessed the letter '" << guess << "'. Try again.\n";
                continue;
            }

            usedLetters += guess;

            if (secretWord.find(guess) != std::string::npos) {
                std::cout << "Correct guess!\n";
                
                for (int i = 0; i < secretWord.length(); i++) {
                    if (secretWord[i] == guess) {
                        guessedLetters[i] = guess;
                    }
                }
            } else {
                std::cout << "Wrong guess!\n";
                wrongAttempts++;
            }
            
            std::cout << "\n";
        }

        if (guessedLetters == secretWord) {
            std::cout << "Congratulations! You guessed the word: " << secretWord << "\n";
        } else {
            std::cout << "Sorry, you ran out of attempts! The word was: " << secretWord << "\n";
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    return 0;
}