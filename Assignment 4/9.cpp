#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double milk, costPerLiter, profitPerCarton;
    cout << "Enter milk produced (liters): ";
    cin >> milk;
    cout << "Enter cost per liter: ";
    cin >> costPerLiter;
    cout << "Enter profit per carton: ";
    cin >> profitPerCarton;

    int cartons = round(milk / 3.78);
    double cost = milk * costPerLiter;
    double profit = cartons * profitPerCarton;

    cout << "Cartons: " << cartons << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Profit: $" << profit;
    return 0;
}
