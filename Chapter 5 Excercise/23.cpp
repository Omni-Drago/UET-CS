#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int i;
    int j;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 10; j++)
            cout << setw(3) << i * j;
        cout << endl;
    }

    return 0;
}