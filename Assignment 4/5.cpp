#include <iostream>
using namespace std;

int main() {
    double price, markup, taxRate, selling, tax, finalPrice;
    cout << "Enter original price: ";
    cin >> price;
    cout << "Enter markup percentage: ";
    cin >> markup;
    cout << "Enter sales tax rate: ";
    cin >> taxRate;

    selling = price + (price * markup / 100);
    tax = selling * taxRate / 100;
    finalPrice = selling + tax;

    cout << "Original Price = " << price << endl;
    cout << "Markup % = " << markup << endl;
    cout << "Selling Price = " << selling << endl;
    cout << "Sales Tax = " << tax << endl;
    cout << "Final Price = " << finalPrice;
    return 0;
}
