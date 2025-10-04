#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double milk, cartons, cost, profit;
    cout << "Enter total milk produced (liters): ";
    cin >> milk;

    cartons = round(milk / 3.78);
    cost = milk * 0.38;
    profit = cartons * 0.27;

    cout << "Cartons needed: " << cartons << endl;
    cout << "Cost of production: $" << cost << endl;
    cout << "Profit: $" << profit;
    return 0;
}
