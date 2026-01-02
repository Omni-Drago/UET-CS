#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int inputNumber, digit, sumOfDigits, tempNumber, digitCount, i;

    cout << "Enter an integer: ";
    cin >> inputNumber;

    if (inputNumber == 0) {
        cout << "Digit: 0 \n";
        cout << "sum = 0";
        return 0; 
    }

    int processingNumber = abs(inputNumber);

    sumOfDigits = 0;
    tempNumber = processingNumber;
    digitCount = 0;

    while (tempNumber != 0) {
        tempNumber = tempNumber / 10;
        digitCount++;
    }

    tempNumber = processingNumber;

    cout << "Digit: ";
    for (i = digitCount; i > 0; i--) {
        int powerOfTen = static_cast<int>(round(pow(10, i - 1)));
        
        digit = tempNumber / powerOfTen;
        
        cout << digit << " ";
        
        tempNumber -= digit * powerOfTen;
        
        sumOfDigits += digit;
    }

    cout << "\nsum = " << sumOfDigits;

    return 0;
}