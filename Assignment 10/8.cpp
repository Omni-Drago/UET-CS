#include <iostream>

using namespace std;

int main() {
    int lillysAge;
    int washingMachinePrice;
    int toyPrice;
    int toyCount = 0;
    int totalSavedMoney = 0;
    int currentMoneyGift = 10;
    int i;
    int moneyFromToys;
    int moneyLeft;
    int moneyNeeded;

    cin >> lillysAge;
    cin >> washingMachinePrice;
    cin >> toyPrice;

    for (i = 1; i <= lillysAge; ++i) {
        
        if (i % 2 == 0) {
            totalSavedMoney = totalSavedMoney + currentMoneyGift;
            totalSavedMoney = totalSavedMoney - 1;
            currentMoneyGift = currentMoneyGift + 10;
        } else {
            toyCount++;
        }
    }

    moneyFromToys = toyCount * toyPrice;
    totalSavedMoney = totalSavedMoney + moneyFromToys;

    if (totalSavedMoney >= washingMachinePrice) {
        moneyLeft = totalSavedMoney - washingMachinePrice;
        cout << "Yes! " << moneyLeft << endl;
    } else {
        moneyNeeded = washingMachinePrice - totalSavedMoney;
        cout << "No! " << moneyNeeded << endl;
    }

    return 0;
}