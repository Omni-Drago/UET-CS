#include <iostream>
using namespace std;

int main() {
    int shares;
    double buyPrice, sellPrice;
    cout << "Enter number of shares: ";
    cin >> shares;
    cout << "Enter purchase price per share: ";
    cin >> buyPrice;
    cout << "Enter selling price per share: ";
    cin >> sellPrice;

    double invest = shares * buyPrice;
    double amountSold = shares * sellPrice;
    double serviceBuy = invest * 0.015;
    double serviceSell = amountSold * 0.015;
    double totalService = serviceBuy + serviceSell;
    double gainLoss = amountSold - invest - totalService;

    cout << "Amount invested = $" << invest << endl;
    cout << "Total service charges = $" << totalService << endl;
    cout << "Amount gained/lost = $" << gainLoss << endl;
    cout << "Amount received = $" << amountSold - serviceSell;
    return 0;
}
