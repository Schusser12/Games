#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    char playAgain;

    do {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int secretNumber = std::rand() % 100 + 1;

        int guess;
        int attempts = 0;
        bool guessed = false;

        std::cout << "*** Number Guessing Game ***\n\n";

        while (!guessed) {
            std::cout << "Enter your guess (1-100): ";
            std::cin >> guess;

            attempts++;

            if (guess == secretNumber) {
                std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
                guessed = true;
            } else if (guess < secretNumber) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "Too high! Try again.\n";
            }
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    return 0;
}