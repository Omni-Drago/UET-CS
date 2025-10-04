#include <iostream>
using namespace std;

int main() {
    double size;
    cout << "Enter hard drive size (GB): ";
    cin >> size;

    double bytes = size * 1000000000.0;
    double actual = bytes / (1024.0 * 1024 * 1024);
    cout << "Actual storage = " << actual << " GB";
    return 0;
}
