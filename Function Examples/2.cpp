#include <iostream>
using namespace std;

// Function Prototype
double larger(double x, double y);

int main() 
{
    double num1 = 13.00;
    double num2 = 36.53;
    double maxNum;

    // Line 1
    cout << "The larger of 5 and 6 is " << larger(5, 6)
         << endl; 

    // Line 2
    cout << "The larger of " << num1 << " and " << num2
         << " is " << larger(num1, num2) << endl; 

    // Line 3
    cout << "The larger of " << num1 << " and 29 is "
         << larger(num1, 29) << endl; 

    // Line 4
    maxNum = larger(38.45, 56.78); 
    cout << "maxNum is " << maxNum << endl;

    return 0;
}

// Function Definition
double larger(double x, double y)
{
    if (x >= y)
        return x;
    else
        return y;
}