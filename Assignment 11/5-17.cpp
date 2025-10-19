#include <iostream>
using namespace std;

int main()
{
    int counter;
    int sum;
    int N;

    cout << "Line 8: Enter the number of positive "
         << "integers to be added: ";
    cin >> N;

    sum = 0;
    cout << endl;

    for (counter = 1; counter <= N; counter++)
        sum = sum + counter;

    cout << "Line 14: The sum of the first " << N
         << " positive integers is " << sum
         << endl;

    return 0;
}