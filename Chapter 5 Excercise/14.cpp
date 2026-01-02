#include <iostream>

using namespace std;

int main() {
    long long x;
    long long largestNum;
    int k = 0;
    int largestPos = 1;
    int currentPos = 1;

    cout << "Enter a positive integer: ";
    cin >> x;

    largestNum = x;

    cout << x << " ";

    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 3 * x + 1;
        }
        
        k++;
        currentPos++;
        cout << x << " ";

        if (x > largestNum) {
            largestNum = x;
            largestPos = currentPos;
        }
    }

    cout << endl;
    cout << "k = " << k << endl;
    cout << "Largest number: " << largestNum << endl;
    cout << "Position of largest number: " << largestPos << endl;

    return 0;
}