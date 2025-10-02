#include <iostream>
using namespace std;

int main()
{
    int weight, days;

    cout << "Enter weight to lose (in kg): ";
    cin >> weight;

    days = weight * 15;

    cout << "It will take " << days << " days to lose " << weight << " kg." << endl;

    return 0;
}
