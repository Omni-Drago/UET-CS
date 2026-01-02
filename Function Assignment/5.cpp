#include <iostream>
using namespace std;

int largest(int a, int b, int c);

int main()
{
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    int maxVal = largest(num1, num2, num3);
    cout << "The largest number is: " << maxVal << endl;

    return 0;
}

int largest(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}