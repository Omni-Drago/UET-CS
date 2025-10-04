#include <iostream>
using namespace std;

int main() {
    double gallons, mpg;
    cout << "Enter fuel tank capacity (gallons): ";
    cin >> gallons;
    cout << "Enter miles per gallon: ";
    cin >> mpg;
    cout << "Car can travel " << gallons * mpg << " miles.";
    return 0;
}
