#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::string choices[] = { "Rock", "Paper", "Scissors" };
    int numOfChoices = sizeof(choices) / sizeof(choices[0]);

    // Generate a random number between 0 and 2
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    char playAgain;
    do {
        int computerChoice = std::rand() % numOfChoices;

        int playerChoice;

        std::cout << "*** Rock, Paper, Scissors ***\n\n";

        // Get the player's choice
        std::cout << "Choose your move:\n";
        std::cout << "1. Rock\n";
        std::cout << "2. Paper\n";
        std::cout << "3. Scissors\n";
        std::cin >> playerChoice;

        playerChoice--; // Adjusting for 0-based indexing

        // Validate the player's choice
        if (playerChoice >= 0 && playerChoice < numOfChoices) {
            std::cout << "You chose: " << choices[playerChoice] << "\n";
            std::cout << "The computer chose: " << choices[computerChoice] << "\n\n";

            // Determine the winner
            int result = (playerChoice - computerChoice + numOfChoices) % numOfChoices;

            if (result == 0) {
                std::cout << "It's a tie!\n";
            } else if (result <= numOfChoices / 2) {
                std::cout << "Congratulations! You win!\n";
            } else {
                std::cout << "Sorry! You lose!\n";
            }
        } else {
            std::cout << "Invalid choice.\n";
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    return 0;
}