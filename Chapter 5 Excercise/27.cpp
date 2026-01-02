#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double R;
    double x;
    const double PI = 3.141592653589793;

    cout << "Enter the radius of the circular waxed paper: ";
    cin >> R;

    x = 2.0 * PI * R * (1.0 - sqrt(2.0 / 3.0));

    cout << fixed << setprecision(2);
    cout << "The length of the removed sector is: " << x << endl;

    return 0;
}