#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    const int MIN = 1;
    const int MAX = 100;

    int randomNumber = rand() % (MAX - MIN + 1) + MIN;

    int numGuesses = 0;
    int guess;

    while (true) {
        cout << "Guess a number between " << MIN << " and " << MAX << ": ";
        cin >> guess;

        numGuesses++;

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number in " << numGuesses << " tries.\n";
            break;
        }
        else if (guess > randomNumber) {
            cout << "Too high. Try again.\n";
        }
        else {
            cout << "Too low. Try again.\n";
        }
    }

    return 0;
}