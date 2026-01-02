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
    int i = firstNum;
    while (i <= secondNum) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;

    int evenSum = 0;
    i = firstNum; 
    while (i <= secondNum) {
        if (i % 2 == 0) {
            evenSum = evenSum + i;
        }
        i++;
    }
    cout << "Sum of even numbers between " << firstNum << " and " << secondNum << ": " << evenSum << endl;

    cout << "Numbers and their squares from 1 to 10:" << endl;
    int j = 1;
    while (j <= 10) {
        cout << j << "   " << (j * j) << endl;
        j++;
    }

    long long oddSquareSum = 0;
    i = firstNum;
    while (i <= secondNum) {
        if (i % 2 != 0) {
            oddSquareSum = oddSquareSum + (long long)i * i;
        }
        i++;
    }
    cout << "Sum of the squares of odd numbers between " << firstNum << " and " << secondNum << ": " << oddSquareSum << endl;

    cout << "Uppercase letters:" << endl;
    char letter = 'A';
    while (letter <= 'Z') {
        cout << letter << " ";
        letter++;
    }
    cout << endl;

    return 0;
}