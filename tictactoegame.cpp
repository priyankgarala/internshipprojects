#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isValidMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col]!= 'X' && board[row][col]!= 'O';
}

void makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
}

bool isWinner() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j]!= 'X' && board[i][j]!= 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int move;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        if (isValidMove(move)) {
            makeMove(move);
            if (isWinner()) {
                printBoard();
                cout << "Player " << (currentPlayer == 'X'? 'O' : 'X') << " wins!" << endl;
                break;
            } else if (isBoardFull()) {
                printBoard();
                cout << "It's a tie!" << endl;
                break;
            }
        } else {
            cout << "Invalid move, try again." << endl;
        }
    }
    return 0;
}