#include <iostream>
using namespace std;

int addNumbers(int a, int b);

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int sum = addNumbers(a, b);
    cout << "Sum: " << sum << endl;

    return 0;
}

int addNumbers(int a, int b)
{
    return a + b;
}