#include <iostream>
using namespace std;
const double PI = 3.141593;

int main() {
    double r;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Area = " << PI * r * r << endl;
    cout << "Circumference = " << 2 * PI * r;
    return 0;
}
