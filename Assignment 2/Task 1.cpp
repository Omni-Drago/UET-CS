#include <iostream>
using namespace std;

int main()
{
    int n, sum;

    cout << "Enter number of sides: ";
    cin >> n;

    sum = (n - 2) * 180;

    cout << "Sum of all the measures of the angles of an n-sided polygon is: " << sum;

    return 0;
}
