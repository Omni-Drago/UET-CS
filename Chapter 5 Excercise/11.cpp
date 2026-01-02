#include <iostream>

using namespace std;

int main() {
    int firstNum, secondNum;
    int nthPosition;
    int currentNum;

    do {
        cout << "Enter two nonnegative integers (first <= second): ";
        cin >> firstNum >> secondNum;

        if (firstNum < 0 || secondNum < 0) {
            cout << "Error: Both numbers must be nonnegative." << endl;
        } else if (firstNum > secondNum) {
            cout << "Error: The first number must be less than or equal to the second." << endl;
        }
    } while (firstNum < 0 || secondNum < 0 || firstNum > secondNum);

    do {
        cout << "Enter the positive position (>= 1) of the desired number: ";
        cin >> nthPosition;
        if (nthPosition <= 0) {
            cout << "Error: Position must be positive." << endl;
        }
    } while (nthPosition <= 0);

    if (nthPosition == 1) {
        currentNum = firstNum;
    } else if (nthPosition == 2) {
        currentNum = secondNum;
    } else {
        int temp;
        for (int counter = 3; counter <= nthPosition; counter++) {
            temp = firstNum + secondNum;
            firstNum = secondNum;
            secondNum = temp;
        }
        currentNum = secondNum;
    }

    cout << "The Fibonacci number at position " << nthPosition << " is: " << currentNum << endl;

    return 0;
}