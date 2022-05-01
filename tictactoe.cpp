/*
Vertical length -> 7
Horizontal row length -> 13
Cell space -> 3 (2 space + 1 char)
1234567890123
------------- (0)
| X | O | X | (1)
------------- (2) 
| X | O | X | (3)
------------- (4)
| X | O | X | (5)
------------- (6)
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

bool tictactoe(char moveData[3][3]) {
    // Horizontal and vertical check
    // Direct comparison a == b == c fails for a reason;
    for (int i = 0; i < 3; i++) {
        if (moveData[i][0] == moveData[i][1] && moveData[i][1] == moveData[i][2]) {
            return true;
        }
        if (moveData[0][i] == moveData[1][i] && moveData[1][i] == moveData[2][i]) {
            return true;
        }
    }
    // Main diagonal check
    if (moveData[0][0] == moveData[1][1] && moveData[1][1] == moveData[2][2]) {
        return true;
    }
    // Reverse diagonal check
    if (moveData[2][0] == moveData[1][1] && moveData[1][1] == moveData[0][2]) {
        return true;
    }
    return false;
}

bool evalSubmit(char moveData[3][3], int position, int playerId) {
    int xIndex = floor((position - 0.1) / 3);
    int yIndex = (position - 3 * xIndex) - 1;
    if (moveData[xIndex][yIndex] != 'X' || moveData[xIndex][yIndex] != 'Y') {
        moveData[xIndex][yIndex] = playerId == 1 ? 'X' : 'O';
        return true;
    } else {
        cout << "\033[1;31mA player has already placed a value here or you typed a value out of table range\033[0;37m" << endl;
        return false;
    }
}

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef __unix__
        system("clear");
    #endif 
}

void resetMoves(char moves[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            moves[i][j] = ' ';
        }
    }
}

void renderTable(char moves[3][3]) {
    int dataRowCounter = 0;
    for (int lineCount = 0; lineCount < 7; lineCount++) {
        // Even case => seperation line
        if (lineCount % 2 == 0) {
            for (int colCount = 0; colCount < 19; colCount++) {
                cout << '+';
            }
        // Odd case => moves line
        } else {
            cout << '+';
            for (int colCount = 0; colCount < 3; colCount++) {
                cout << "  " << moves[dataRowCounter][colCount] << "  +";
            }
            dataRowCounter++;
        }
        cout << endl;
    }
}

int main() {
    int empty_places = 9;
    int player_playing = 1;
    cout << "Welcome to Tic Tac Toe by Antonis Anagnostou" << endl << "You can review the play positions below:" << endl << endl;
    char moves[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    renderTable(moves);
    // If this function is used game logic will immediately evaluate to win
    // resetMoves();
    while (empty_places != 0) {
        int position = 0;
        cout << "Player " << player_playing << " <" << (player_playing == 1 ? "X" : "O") << "> choose a position: ";
        cin >> position;
        if (evalSubmit(moves, position, player_playing)) {
            if (tictactoe(moves)) {
                clearTerminal();
                renderTable(moves);
                cout << player_playing == 1 ? "\033[1;32mPlayer 1 wins! Congratulations!\033[0;37m" : "\033[1;32mPlayer 2 wins! Congratulations!\033[0;37m" << endl;
                return 0;
            };
            player_playing = player_playing == 1 ? 2 : 1;
            clearTerminal();
            renderTable(moves);
            empty_places--;
        };
    }
    cout << endl << "Game ended - DRAW!";
    return 0;
}

