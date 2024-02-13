#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string choices[] = { "Rock", "Paper", "Scissors" };
    int numOfChoices = sizeof(choices) / sizeof(choices[0]);

    // Generate a random number between 0 and 2
    srand(static_cast<unsigned int>(time(0)));

    char playAgain;
    do {
        int computerChoice = rand() % numOfChoices;

        int playerChoice;

        cout << "*** Rock, Paper, Scissors ***\n\n";

        // Get the player's choice
        cout << "Choose your move:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cin >> playerChoice;
		

        playerChoice--; // Adjusting for 0-based indexing

        // Validate the player's choice
        if (playerChoice >= 0 && playerChoice < numOfChoices) {
            cout << "You chose: " << choices[playerChoice] << "\n";
            cout << "The computer chose: " << choices[computerChoice] << "\n\n";

            // Determine the winner
            int result = (playerChoice - computerChoice + numOfChoices) % numOfChoices;

            if (result == 0) {
                cout << "It's a tie!\n";
            } else if (result <= numOfChoices / 2) {
                cout << "Congratulations! You win!\n";
            } else {
                cout << "Sorry! You lose!\n";
            }
        } else {
            cout << "Invalid choice.\n";
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    return 0;
}
