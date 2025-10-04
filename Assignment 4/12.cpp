#include <iostream>
using namespace std;

int main() {
    double fixed, percent, cost, minAdd, maxAdd;
    cout << "Enter fixed commission: ";
    cin >> fixed;
    cout << "Enter commission percentage: ";
    cin >> percent;
    cout << "Enter car cost: ";
    cin >> cost;
    cout << "Enter min and max amount to add: ";
    cin >> minAdd >> maxAdd;

    double minSell = cost + minAdd;
    double maxSell = cost + maxAdd;

    double minComm = fixed + (minSell - cost) * percent / 100;
    double maxComm = fixed + (maxSell - cost) * percent / 100;

    cout << "Min Selling Price = " << minSell << endl;
    cout << "Max Selling Price = " << maxSell << endl;
    cout << "Commission Range = " << minComm << " - " << maxComm;
    return 0;
}
