#include <iostream>
using namespace std;
int main() {
    int i;

    for (i = 10; i <= 9; i++)
        cout << i << " ";
    cout << endl;

    for (i = 9; i >= 10; i--)
        cout << i << " ";
    cout << endl;

    for (i = 10; i <= 10; i++)
        cout << i << " ";
    cout << endl;

    for (i = 1; i <= 10; i++);
        cout << i << " ";
    cout << endl;

    for (i = 1; ; i++)
        cout << i << " ";
    cout << endl;

    for (i = 2; i < 100; i = 2 * i)
        cout << i << " ";
    cout << endl;

    return 0;
}