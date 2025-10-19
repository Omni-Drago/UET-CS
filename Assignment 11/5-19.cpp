#include <iostream>
using namespace std;
int main() {
    int i;

    i = 11;
    while (i <= 10)
    {
        cout << i << " ";
        i = i + 5;
    }
    cout << endl;

    i = 11;
    do
    {
        cout << i << " ";
        i = i + 5;
    }
    while (i <= 10);
    cout << endl;

    return 0;
}