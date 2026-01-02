#include <iostream>

using namespace std;

int main() {
    int totalUnits;
    double baseRent;
    double rentIncrease;
    double maintenanceCost;
    
    int unitsForMaxProfit = 0;
    double maxProfit = -1.0;

    cout << "Enter the total number of units: ";
    cin >> totalUnits;

    cout << "Enter the rent to occupy all the units: ";
    cin >> baseRent;

    cout << "Enter the increase in rent that results in a vacant unit: ";
    cin >> rentIncrease;

    cout << "Enter the amount to maintain a rented unit: ";
    cin >> maintenanceCost;

    for (int vacantUnits = 0; vacantUnits <= totalUnits; vacantUnits++) {
        int occupiedUnits = totalUnits - vacantUnits;
        double currentRent = baseRent + (vacantUnits * rentIncrease);
        
        double totalRevenue = occupiedUnits * currentRent;
        double totalMaintenance = occupiedUnits * maintenanceCost;
        
        double currentProfit = totalRevenue - totalMaintenance;

        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            unitsForMaxProfit = occupiedUnits;
        }
    }

    cout << endl;
    cout << "The number of units to be rented to maximize the profit is: " 
         << unitsForMaxProfit << endl;

    return 0;
}