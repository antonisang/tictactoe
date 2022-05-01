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

bool evalSubmit(char moveData[3][3], int position, int playerId) {
    int xIndex = floor((position - 0.1) / 3);
    int yIndex = (position - 3 * xIndex) - 1;
    if (moveData[xIndex][yIndex] == ' ') {
        moveData[xIndex][yIndex] = playerId == 1 ? 'X' : 'O';
        return true;
    } else {
        cout << "A player has already placed a value here" << endl;
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
    resetMoves(moves);
    while (empty_places != 0) {
        int position = 0;
        cout << "Player " << player_playing << " <" << (player_playing == 1 ? "X" : "O") << "> choose a position: ";
        cin >> position;
        if (evalSubmit(moves, position, player_playing)) {
            player_playing = player_playing == 1 ? 2 : 1;
            empty_places--;
        };
    }
    cout << endl << "Game ended thanks for playing!";
    // renderTable(moves);
    return 0;
}

