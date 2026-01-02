#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int itemCount = 0;
    double itemPrice;
    double totalCost = 0.0;
    double shippingCost = 0.0;
    double totalBillingAmount = 0.0;

    cout << "Enter the price for each item." << endl;
    cout << "Enter 0 or a negative number to finish." << endl;

    for (;;) {
        cout << "Enter price for item " << (itemCount + 1) << ": ";
        cin >> itemPrice;

        if (itemPrice <= 0.0) {
            break;
        }

        totalCost = totalCost + itemPrice;
        itemCount++;
    }

    if (itemCount > 0 && totalCost < 200.0) {
        shippingCost = 10.0 * itemCount;
    }

    totalBillingAmount = totalCost + shippingCost;

    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Total items: " << itemCount << endl;
    cout << "Total cost of items: $" << totalCost << endl;
    cout << "Shipping & Handling: $" << shippingCost << endl;
    cout << "Total billing amount: $" << totalBillingAmount << endl;

    return 0;
}