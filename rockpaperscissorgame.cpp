#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); // seed for random number generation

    int userScore = 0, computerScore = 0;

    char userChoice, computerChoice;

    cout << "Welcome to Rock Paper Scissors game!" << endl;
    cout << "Enter your choice (R for Rock, P for Paper, S for Scissors):" << endl;

    while (true) {
        cin >> userChoice;
        userChoice = toupper(userChoice); // convert to uppercase

        if (userChoice != 'R' && userChoice != 'P' && userChoice != 'S') {
            cout << "Invalid choice. Please enter R, P or S." << endl;
            continue;
        }

        // generate computer's choice
        int random = rand() % 3;
        switch (random) {
            case 0:
                computerChoice = 'R';
                break;
            case 1:
                computerChoice = 'P';
                break;
            case 2:
                computerChoice = 'S';
                break;
        }

        cout << "Computer's choice: " << computerChoice << endl;

        // determine the winner
        if (userChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((userChoice == 'R' && computerChoice == 'S') ||
                   (userChoice == 'P' && computerChoice == 'R') ||
                   (userChoice == 'S' && computerChoice == 'P')) {
            cout << "You win this round!" << endl;
            userScore++;
        } else {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }

        cout << "Score - You: " << userScore << ", Computer: " << computerScore << endl;
        cout << "Enter your choice (R for Rock, P for Paper, S for Scissors) or 'Q' to quit:" << endl;
    }

    return 0;
}