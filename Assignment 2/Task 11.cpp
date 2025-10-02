#include <iostream>
using namespace std;

int main()
{
    int age, moves, houses;
    double average;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter number of times moved: ";
    cin >> moves;

    houses = moves + 1;
    average = (double)age / houses;

    cout << "Average years in one house: " << average << endl;

    return 0;
}
