#include <iostream>
using namespace std;

void evenOddTransform(int arr[], int size, int n) {
    for (int count = 0; count < n; count++) {
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0) {
                arr[i] = arr[i] + 2;
            } else {
                arr[i] = arr[i] - 2;
            }
        }
    }
}

int main() {
    int arr[] = {3, 4, 9};
    int size = 3;
    int n;

    cout << "Enter number of transformations: ";
    cin >> n;

    evenOddTransform(arr, size, n);

    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}