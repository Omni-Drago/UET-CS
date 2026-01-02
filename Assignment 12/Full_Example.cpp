#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i <= 10; i++) {
        cout << "i=" << i << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    for (int x = 10; x >= 1; x -= 2) {
        cout << "num (x) =" << x << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    int sum = 0;
    for (int i = 5; i <= 50; i += 3) {
        sum += i;
    }
    cout << "The sum is: " << sum << endl;
    cout << "--------------------------------------------------------------------" << endl;

    char ch;
    for (int i = 0; i <= 5; i++) {
        cout << "Enter charactar " << i << " :";
        cin >> ch;
        if (ch == 'n')
            break;
    }
    cout << "--------------------------------------------------------------------" << endl;

    for (int n = 10; n > 0; n--) {
        if (n == 5)
            continue;
        cout << n << ", ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (int multi = 0; multi <= 5; multi++) {
        for (int multi2 = 0; multi2 <= 10; multi2++) {
            cout << multi << " * " << multi2 << " = " << multi * multi2 << endl;
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    for (int x = 1; x <= 5; x++) {
        for (int y = 1; y <= x; y++)
            cout << "*";
        cout << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    for (int row = 4; row >= 0; row--) {
        for (int space = 4; space > row; space--)
            cout << " ";
        for (int i = 1; i <= row; i++)
            cout << "*";
        cout << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    for (int i = 1; i <= 5; i++) {
        for (int j = 5; j > i; j--)
            cout << " ";
        for (int k = 1; k < 2 * i; k++)
            cout << "*";
        cout << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;

    return 0;
}