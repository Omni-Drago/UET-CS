#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n1, n2, n3, n4, n5, sum;
    cout << "Enter five decimal numbers: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    sum = n1 + n2 + n3 + n4 + n5;
    cout << "Rounded sum = " << round(sum);
    return 0;
}
