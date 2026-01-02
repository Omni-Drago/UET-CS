#include <iostream>

using namespace std;

int main() {
    long popA, popB;
    double rateA, rateB;
    int years = 0;

    do {
        cout << "Enter population of town A: ";
        cin >> popA;
        cout << "Enter growth rate of town A (e.g., 4 for 4%): ";
        cin >> rateA;
        
        cout << "Enter population of town B: ";
        cin >> popB;
        cout << "Enter growth rate of town B (e.g., 2 for 2%): ";
        cin >> rateB;

        if (popA >= popB) {
            cout << "Error: Town A's population must be less than Town B's." << endl;
        }
        if (rateA <= rateB) {
            cout << "Error: Town A's growth rate must be greater than Town B's." << endl;
        }

    } while (popA >= popB || rateA <= rateB);

    double decimalRateA = rateA / 100.0;
    double decimalRateB = rateB / 100.0;

    while (popA < popB) {
        years++;
        popA = popA + (long)(popA * decimalRateA);
        popB = popB + (long)(popB * decimalRateB);
    }

    cout << endl;
    cout << "After " << years << " years:" << endl;
    cout << "The population of town A will be " << popA << "." << endl;
    cout << "The population of town B will be " << popB << "." << endl;

    return 0;
}