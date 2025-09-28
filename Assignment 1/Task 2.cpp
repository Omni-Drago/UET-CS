#include <iostream>
using namespace std;

int main()
{
    float lbs, kg;

    cout << "Enter Weight in Pounds (lbs): ";
    cin >> lbs;

    kg = lbs * 0.45;  

    cout << "Weight in Kilograms is: " << kg;

    return 0;
}
