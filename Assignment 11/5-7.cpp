#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int num;

    cin >> num;
    while (cin)
    {
        sum = sum + num;
        cin >> num;
    }
    cout << "Sum = " << sum << endl;

    return 0;
}