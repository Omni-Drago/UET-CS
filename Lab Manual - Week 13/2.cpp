#include <iostream>
using namespace std;

int main() {
    int value = 10;
    int* ptr = &value;

    cout << "Original value: " << value << endl;


    *ptr = 25;

    cout << "Modified value: " << value << endl;

    return 0;
}