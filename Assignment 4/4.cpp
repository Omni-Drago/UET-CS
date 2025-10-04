#include <iostream>
using namespace std;

int main() {
    int seconds, h, m, s;
    cout << "Enter elapsed time in seconds: ";
    cin >> seconds;

    h = seconds / 3600;
    seconds %= 3600;
    m = seconds / 60;
    s = seconds % 60;

    cout << h << ":" << m << ":" << s;
    return 0;
}
