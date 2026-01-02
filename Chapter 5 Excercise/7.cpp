#include <iostream>

using namespace std;

int main() {
    long long n;
    int alternatingSum = 0;
    int sign = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    long long originalNumber = n;

    while (n > 0) {
        int digit = n % 10;
        alternatingSum = alternatingSum + (digit * sign);
        sign = -sign;
        n = n / 10;
    }

    if (alternatingSum % 11 == 0) {
        cout << originalNumber << " is divisible by 11." << endl;
    } else {
        cout << originalNumber << " is not divisible by 11." << endl;
    }

    return 0;
}