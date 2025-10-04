#include <iostream>
using namespace std;

int main() {
    int q, d, n, total;
    cout << "Enter quarters, dimes, nickels: ";
    cin >> q >> d >> n;
    total = q * 25 + d * 10 + n * 5;
    cout << "Total in pennies = " << total;
    return 0;
}
