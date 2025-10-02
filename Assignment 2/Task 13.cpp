#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum;

    sum = 0;

    cout << "Enter 5 integers:" << endl;

    cin >> num;
    sum = sum + num;

    cin >> num;
    sum = sum + num;

    cin >> num;
    sum = sum + num;

    cin >> num;
    sum = sum + num;

    cin >> num;
    sum = sum + num;

    cout << "Sum = " << sum << endl;

    return 0;
}
