#include <iostream>

using namespace std;

int main() {
    double inheritedMoney, moneyNeeded;
    int endYear, currentAge = 18, year;

    cin >> inheritedMoney;
    cin >> endYear;

    for (year = 1800; year <= endYear; ++year) {
        
        if (year % 2 == 0) {
            inheritedMoney -= 12000;
        } else {
            inheritedMoney -= (12000 + 50 * currentAge);
        }
        
        currentAge++;
    }

    if (inheritedMoney >= 0) {
        cout << "Yes! He will live a carefree life and will have " << inheritedMoney << " dollars left." << endl;
    } else {
        moneyNeeded = -inheritedMoney; 
        cout << "He will need " << moneyNeeded << " dollars to survive." << endl;
    }

    return 0;
}