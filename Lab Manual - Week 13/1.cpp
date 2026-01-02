#include <iostream>
using namespace std;

int main() {
    int number = 100;
    int* ptr = &number;

    cout << "Value of variable: " << number << endl;
    cout << "Address of variable: " << ptr << endl;
    cout << "Value accessed through pointer: " << *ptr << endl;

    return 0;
}