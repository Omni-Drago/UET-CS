#include <iostream>

using namespace std;

int main() {
    int firstNum, secondNum;

    do {
        cout << "Enter first integer: ";
        cin >> firstNum;
        cout << "Enter second integer: ";
        cin >> secondNum;

        if (firstNum >= secondNum) {
            cout << "First number must be less than the second number." << endl;
            cout << "Please re-enter both integers." << endl;
        }
    } while (firstNum >= secondNum);

    cout << "Odd numbers between " << firstNum << " and " << secondNum << ":" << endl;
    int i = firstNum;
    do {
        if (i % 2 != 0) {
            cout << i << " ";
        }
        i++;
    } while (i <= secondNum);
    cout << endl;

    int evenSum = 0;
    i = firstNum; 
    do {
        if (i % 2 == 0) {
            evenSum = evenSum + i;
        }
        i++;
    } while (i <= secondNum);
    cout << "Sum of even numbers between " << firstNum << " and " << secondNum << ": " << evenSum << endl;

    cout << "Numbers and their squares from 1 to 10:" << endl;
    int j = 1;
    do {
        cout << j << "   " << (j * j) << endl;
        j++;
    } while (j <= 10);

    long long oddSquareSum = 0;
    i = firstNum;
    do {
        if (i % 2 != 0) {
            oddSquareSum = oddSquareSum + (long long)i * i;
        }
        i++;
    } while (i <= secondNum);
    cout << "Sum of the squares of odd numbers between " << firstNum << " and " << secondNum << ": " << oddSquareSum << endl;

    cout << "Uppercase letters:" << endl;
    char letter = 'A';
    do {
        cout << letter << " ";
        letter++;
    } while (letter <= 'Z');
    cout << endl;

    return 0;
}