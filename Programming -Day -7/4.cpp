#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int totalNumbers, currentNumber;
    double percentDivBy2, percentDivBy3, percentDivBy4;
    int divBy2Count = 0, divBy3Count = 0, divBy4Count = 0;

    cout << "Enter the count of numbers[1-1000]: ";
    cin >> totalNumbers;

    for (int i = 0; i < totalNumbers; i++) {
        cin >> currentNumber;

        if (currentNumber % 2 == 0) {
            divBy2Count++;
        }
        if (currentNumber % 3 == 0) {
            divBy3Count++;
        }
        if (currentNumber % 4 == 0) {
            divBy4Count++;
        }
    }

    percentDivBy2 = (divBy2Count * 100.0) / totalNumbers;
    percentDivBy3 = (divBy3Count * 100.0) / totalNumbers;
    percentDivBy4 = (divBy4Count * 100.0) / totalNumbers;

    cout << fixed << setprecision(2);

    cout << "p1 = " << percentDivBy2 << " % " << endl;
    cout << "p2 = " << percentDivBy3 << " % " << endl;
    cout << "p3 = " << percentDivBy4 << " % " << endl;

    return 0;
}