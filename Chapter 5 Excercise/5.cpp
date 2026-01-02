#include <iostream>
using namespace std;
int main() {
    int num1, num2;
    int multiplesOf3 = 0;
    int multiplesOf5 = 0;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    int start, end;

    if (num1 < num2) {
        start = num1;
        end = num2;
    } else {
        start = num2;
        end = num1;
    }

    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            multiplesOf3++;
        }
        if (i % 5 == 0) {
            multiplesOf5++;
        }
    }

    cout << "Multiples of 3: " << multiplesOf3 << std::endl;
    cout << "Multiples of 5: " << multiplesOf5 << std::endl;

    return 0;
}