#include <iostream>
using namespace std;

int main() {
    int T, row, space, i;

    cout << "Enter the number of rows: ";
    cin >> T;

    for (row = 1; row <= T; row++) {
        
        for (space = 1; space <= T - row; space++) {
            cout << " ";
        }

        for (i = 1; i <= row; i++) {
            cout << "* ";
        }
        
        cout << endl;
    }

    return 0;
}

