#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double E_VALUE = 2.718281827;
    double expressionValue;

    cout << fixed << setprecision(9);
    cout << "Value of n   |   Computed e      |   Difference" << endl;
    cout << "----------------------------------------------------" << endl;

    for (long long n = 100; n <= 10000; n += 100) {
        expressionValue = pow(1.0 + 1.0 / n, n);
        cout << setw(12) << n << " | " << expressionValue << " | " << (E_VALUE - expressionValue) << endl;
    }

    cout << "\n--- Calculation for 1,000 to 1,000,000 ---" << endl;
    cout << "Value of n   |   Computed e      |   Difference" << endl;
    cout << "----------------------------------------------------" << endl;

    for (long long n = 1000; n <= 1000000; n += 1000) {
        expressionValue = pow(1.0 + 1.0 / n, n);
        if (n % 100000 == 0 || n == 1000) {
             cout << setw(12) << n << " | " << expressionValue << " | " << (E_VALUE - expressionValue) << endl;
        }
    }

    return 0;
}