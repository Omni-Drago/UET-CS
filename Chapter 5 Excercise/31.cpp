#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double e_approx = 1.0;
    long long factorial = 1;

    cout << "Enter a positive integer n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial = factorial * i;
        e_approx = e_approx + (1.0 / factorial);
    }

    cout << fixed << setprecision(15);
    cout << "The value of e approximated with n = " << n << " is: " << e_approx << endl;

    return 0;
}