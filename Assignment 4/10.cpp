#include <iostream>
using namespace std;

int main() {
    double rate, hours, gross, net, clothes, supplies, bonds, parentsBonds;
    double totalHours = 0;

    cout << "Enter hourly pay rate: ";
    cin >> rate;
    cout << "Enter hours worked each week (5 weeks): ";
    for (int i = 0; i < 5; i++) {
        cin >> hours;
        totalHours += hours;
    }

    gross = rate * totalHours;
    net = gross * (1 - 0.14);
    clothes = net * 0.10;
    supplies = net * 0.01;
    bonds = (net - clothes - supplies) * 0.25;
    parentsBonds = bonds * 0.50;

    cout << "Gross Income = $" << gross << endl;
    cout << "Net Income = $" << net << endl;
    cout << "Clothes = $" << clothes << endl;
    cout << "Supplies = $" << supplies << endl;
    cout << "Bonds = $" << bonds << endl;
    cout << "Parents Bonds = $" << parentsBonds;
    return 0;
}
