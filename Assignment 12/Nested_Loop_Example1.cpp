#include <iostream>
using namespace std;
int main()
{
    for (int multi = 0; multi <= 5; multi++) {
        for (int multi2 = 0; multi2 <= 10; multi2++) {
            cout << multi << "*" << multi2 << "=" << multi * multi2 << endl;
        }
        cout << endl;
    }
    return 0;
}