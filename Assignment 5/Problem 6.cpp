#include <iostream>
using namespace std;

int main() {
    double speed;

    cout << "Enter speed: ";
    cin >> speed;

    if (speed <= 10) {
        cout << "slow" << endl;
    } 
    else if (speed > 10 && speed <= 50) {
        cout << "average" << endl;
    } 
    else if (speed > 50 && speed <= 150) {
        cout << "fast" << endl;
    } 
    else if (speed > 150 && speed <= 1000) {
        cout << "Ultra fast" << endl;
    } 
    else {
        cout << "Extremely fast" << endl;
    }

    return 0;
}
