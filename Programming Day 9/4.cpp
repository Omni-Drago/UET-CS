#include <iostream>
#include <string>
using namespace std;

int arr[100];
int size;

string sevenBoom() {
    for (int i = 0; i < size; i++) {
        int temp = arr[i];

        while (temp > 0) {
            int digit = temp % 10;

            if (digit == 7) {
                return "Boom!";
            }

            temp = temp / 10;
        }
    }
    return "there is no 7 in the array";
}

int main() {
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << sevenBoom() << endl;

    return 0;
}