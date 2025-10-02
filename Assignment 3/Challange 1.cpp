#include <iostream>
using namespace std;

int main()
{
    int amount, discount;

    cout << "Enter total amount: ";
    cin >> amount;

    if (amount <= 5000)
    {
        discount = amount * 5 / 100;   // 5% discount
    }
    else
    {
        discount = amount * 10 / 100;  // 10% discount
    }

    amount = amount - discount;

    cout << "Total discount is: " << discount << endl;
    cout << "Bill after discount is: " << amount << endl;

    return 0;
}
