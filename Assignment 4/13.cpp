#include <iostream>
using namespace std;

int main() {
    double m1, m2, d;
    const double k = 6.67e-8;
    cout << "Enter masses (g) and distance (cm): ";
    cin >> m1 >> m2 >> d;
    double F = k * m1 * m2 / (d * d);
    cout << "Force = " << F << " dynes";
    return 0;
}
