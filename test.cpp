#include <cmath>
#include <iostream>

using namespace std;

void calcPosition(int num) {
    int xIndex = floor((num - 0.1) / 3);
    int yIndex = (num - 3 * xIndex) - 1;
    cout << xIndex << endl;
    cout << yIndex;
}

int main() {
    calcPosition(9);
    return 0;
}