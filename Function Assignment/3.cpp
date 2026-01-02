#include <iostream>
using namespace std;

bool isEven(int num);

int main()
{
    int number;
    cout << "Enter number: ";
    cin >> number;

    if (isEven(number))
    {
        cout << "The number is Even." << endl;
    }
    else
    {
        cout << "The number is Odd." << endl;
    }

    return 0;
}

bool isEven(int num)
{
    if (num % 2 == 0)
        return true;
    else
        return false;
}