#include <iostream>
using namespace std;

int main() {
    int num1 = 50;
    int num2 = 100;
    int* ptr;

    ptr = &num1;
    cout << "Value of num1 via pointer: " << *ptr << endl;


    ptr = &num2;
    cout << "Value of num2 via pointer: " << *ptr << endl;

    return 0;
}