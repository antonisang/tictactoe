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

using namespace std;

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
    char moves[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    renderTable(moves);
    delete[] moves;
    moves[3][3] = { ' ' };
    renderTable(moves);
    return 0;
}

