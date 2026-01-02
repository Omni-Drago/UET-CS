#include <iostream>
using namespace std;

int countIdenticalRows(int array[4][3]);

int main() {
    int matrix[4][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {1, 2, 3}, 
        {7, 8, 9}  
    };

    cout << "Identical Rows Count: " << countIdenticalRows(matrix) << endl;

    return 0;
}

int countIdenticalRows(int array[4][3]) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            bool isMatch = true;

            for (int k = 0; k < 3; k++) {
                if (array[i][k] != array[j][k]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                count++;
            }
        }
    }
    return count;
}