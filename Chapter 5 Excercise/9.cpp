#include <iostream>

using namespace std;

int main() {
    int firstNum, secondNum;

    cout << "Enter first integer: ";
    cin >> firstNum;
    cout << "Enter second integer: ";
    cin >> secondNum;

    while (firstNum >= secondNum) {
        cout << "First number must be less than the second number." << endl;
        cout << "Please re-enter both integers." << endl;
        cout << "Enter first integer: ";
        cin >> firstNum;
        cout << "Enter second integer: ";
        cin >> secondNum;
    }

    cout << "Odd numbers between " << firstNum << " and " << secondNum << ":" << endl;
    for (int i = firstNum; i <= secondNum; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    int evenSum = 0;
    for (int i = firstNum; i <= secondNum; i++) {
        if (i % 2 == 0) {
            evenSum = evenSum + i;
        }
    }
    cout << "Sum of even numbers between " << firstNum << " and " << secondNum << ": " << evenSum << endl;

    cout << "Numbers and their squares from 1 to 10:" << endl;
    for (int j = 1; j <= 10; j++) {
        cout << j << "   " << (j * j) << endl;
    }

    long long oddSquareSum = 0;
    for (int i = firstNum; i <= secondNum; i++) {
        if (i % 2 != 0) {
            oddSquareSum = oddSquareSum + (long long)i * i;
        }
    }
    cout << "Sum of the squares of odd numbers between " << firstNum << " and " << secondNum << ": " << oddSquareSum << endl;

    cout << "Uppercase letters:" << endl;
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        cout << letter << " ";
    }
    cout << endl;

    return 0;
}