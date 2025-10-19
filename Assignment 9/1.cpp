// Example 4-3
#include <iostream>
#include <iomanip>

using namespace std;

const double INTEREST_RATE = 0.015;

int main()
{
    double creditCardBalance;
    double payment;
    double balance;
    double penalty = 0.0;

    cout << fixed << showpoint << setprecision(2);
    
    cout << "Line 12: Enter credit card balance: ";
    cin >> creditCardBalance;
    cout << endl;
    
    cout << "Line 15: Enter the payment: ";
    cin >> payment;
    cout << endl;
    
    balance = creditCardBalance - payment;
    
    if (balance > 0)
        penalty = balance * INTEREST_RATE;

    cout << "Line 21: The balance is: $" << balance
         << endl;
    cout << "Line 22: The penalty to be added to your "
         << "next month bill is: $" << penalty << endl;
         
    return 0;
}