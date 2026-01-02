#include <iostream>
using namespace std;

bool isGoal(char field[7][16]);

int main() {
    char field[7][16] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '_', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '}
    };

    if (isGoal(field)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

bool isGoal(char field[7][16]) {
    int ballRow, ballCol;
    int crossbarRow = -1;
    int leftUpright = -1;
    int rightUpright = -1;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 16; j++) {
            if (field[i][j] == '0') {
                ballRow = i;
                ballCol = j;
            }
            
            if (field[i][j] == '-' || field[i][j] == '_') {
                crossbarRow = i;
            }

            if (field[i][j] == '|') {
                if (leftUpright == -1) {
                    leftUpright = j;
                } else {
                    rightUpright = j;
                }
            }
        }
    }

    if (ballRow < crossbarRow && ballCol > leftUpright && ballCol < rightUpright) {
        return true;
    } else {
        return false;
    }
}