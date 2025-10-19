// Example 4-14
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double suitcaseDimension;
    double suitcaseWeight;
    double additionalCharges = 0.0;
    
    cout << fixed << showpoint << setprecision(2);

    cout << "Line 10: Enter suitcase dimensions "
         << "(length + width + depth) in inches: ";
    cin >> suitcaseDimension;
    cout << endl;

    cout << "Line 13: Enter suitcase weight in pounds: ";
    cin >> suitcaseWeight;
    cout << endl;

    if (suitcaseDimension > 108 || suitcaseWeight > 50)
        additionalCharges = 50.00;
        
    cout << "Line 18: Additional suitcase charges: $"
         << additionalCharges << endl;
         
    return 0;
}