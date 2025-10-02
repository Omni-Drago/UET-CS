#include <iostream>
using namespace std;

int main()
{
    int monthsalary, advance, laptopPrice, monthsRequired, shortfall;

    monthsalary = 10000;
    laptopPrice = 50000;
    advance = monthsalary * 50 / 100 * 6;  

    cout << "Ali's advance salary for 6 months: " << advance << endl;

    if (advance >= laptopPrice)
    {
        cout << "Yes, Ali can buy the laptop." << endl;
    }
    else
    {
        cout << "No, Ali cannot buy the laptop." << endl;

        
        monthsRequired = (laptopPrice + monthsalary) / monthsalary; 

        cout << "Ali needs at least " << monthsRequired 
             << " months of full salary to buy the laptop." << endl;

        
        shortfall = laptopPrice - advance;
        cout << "He still needs Rs " << shortfall << " more." << endl;
    }

    return 0;
}
