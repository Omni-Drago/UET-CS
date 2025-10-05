#include <iostream>
using namespace std;

int main() {
    float speed;

    cout << "Enter car speed: ";
    cin >> speed;

    if (speed >= 100) {
        cout << "Halt... YOU WILL BE CHALLANED!!!" << endl;
    } else {
        cout << "Perfect! You’re going good." << endl;
    }

    return 0;
}
