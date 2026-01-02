#include <iostream>

using namespace std;

int main() {
    long long x;
    int k = 0;

    cout << "Enter a positive integer: ";
    cin >> x;

    cout << x << " ";

    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 3 * x + 1;
        }
        k++;
        cout << x << " ";
    }

    cout << endl;
    cout << "k = " << k << endl;

    return 0;
}