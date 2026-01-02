#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int* ptr = arr; 

    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Array elements are: ";
    for (int i = 0; i < 10; i++) {
        
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}