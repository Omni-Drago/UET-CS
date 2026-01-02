#include <iostream>
#include <string>
using namespace std;

string checkTarget(string coordinate, char board[5][5]);

int main() {
    char battleMatrix[5][5] = {
        {'.', '.', '.', '*', '.'}, 
        {'.', '*', '.', '.', '.'}, 
        {'.', '.', '.', '.', '.'}, 
        {'*', '.', '.', '*', '.'}, 
        {'.', '.', '.', '.', '.'}  
    };

    string input;

    cout << "--- BATTLESHIP ---" << endl;
    cout << "Enter coordinate (e.g., A1, D2, E5): ";
    cin >> input;

    cout << "Result: " << checkTarget(input, battleMatrix) << endl;

    return 0;
}

string checkTarget(string coordinate, char board[5][5]) {
    int row = coordinate[0] - 'A'; 
    int col = coordinate[1] - '1';

    if (board[row][col] == '*') {
        return "BOOM";
    } else {
        return "splash";
    }
}