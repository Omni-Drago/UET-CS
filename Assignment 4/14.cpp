#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double pounds;
    cout << "Enter pounds per bag: ";
    cin >> pounds;
    double bags = ceil(2205 / pounds);
    cout << "Bags needed = " << bags;
    return 0;
}
