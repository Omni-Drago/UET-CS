#include <iostream>
using namespace std;

void timesTen(int number);

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    timesTen(num);

    return 0;
}

void timesTen(int number)
{
    int result = number * 10;
    cout << "Result: " << result << endl;
}