#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int test_values[] = {3, 5, 10, 50, 100};

    cout << fixed << setprecision(15);
    
    for (int n : test_values) {
        double frac = 0.0;

        for (int i = n; i >= 1; i--) {
            int term;
            
            if (i % 3 == 2) {
                term = 2 * (i / 3 + 1);
            } else {
                term = 1;
            }

            frac = 1.0 / (term + frac);
        }

        double e_approx = 2.0 + frac;
        cout << "Approximation with n = " << setw(3) << n << ": " << e_approx << endl;
    }

    return 0;
}