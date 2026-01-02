#include <iostream>
using namespace std;

int main() {
    int arr[10] = {5, 12, 88, 4, 23, 99, 15, 60, 1, 74};
    int* ptr = arr;
    int maxVal = *ptr; 

    for (int i = 1; i < 10; i++) {
        
        if (*(ptr + i) > maxVal) {
            maxVal = *(ptr + i);
        }
    }

    cout << "Maximum value in array: " << maxVal << endl;

    return 0;
}