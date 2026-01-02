#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum = sum + *ptr; 
        ptr++;            
    }

    cout << "Sum of array elements: " << sum << endl;

    return 0;
}