#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char currentPlayer = 'X';

void printBoard() {
    cout << " 1 | 2 | 3 | 4 | 5 | 6 | 7" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cout << board[i][j] << " ";
            if (j < 6) {
                cout << "| ";
            }
        }
        cout << endl;
        if (i < 5) {
            cout << "---------------------------" << endl;
        }
    }
}

bool isValidMove(int column) {
    return board[0][column - 1] == ' ';
}

void makeMove(int column) {
    for (int i = 5; i >= 0; i--) {
        if (board[i][column - 1] == ' ') {
            board[i][column - 1] = currentPlayer;
            break;
        }
    }
    currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
}

bool isWinner() {
    // check horizontal
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }
    // check vertical
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }
    // check diagonal (top-left to bottom-right)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }
    // check diagonal (bottom-left to top-right)
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != ' ' && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int column;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-7): ";
        cin >> column;
        if (isValidMove(column)) {
            makeMove(column);
            if (isWinner()) {
                printBoard();
                cout << "Player " << (currentPlayer == 'X'? 'O' : 'X') << " wins!" << endl;
                break;
            }
        } else {
            cout << "Invalid move, try again." << endl;
        }
    }
    return 0;
}