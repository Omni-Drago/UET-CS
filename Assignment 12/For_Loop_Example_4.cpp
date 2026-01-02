#include <iostream>
using namespace std;
int main() {
    char ch;
    for (int i = 0; i <= 5; i++) {
        cout << "Enter charactar " << i << " :";
        cin >> ch;
        if (ch == 'n')
            break;
    }
    cout << endl;
    return 0;
}

