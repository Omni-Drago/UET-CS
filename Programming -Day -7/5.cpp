#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int busPricePerTon = 200;
    const int truckPricePerTon = 175;
    const int trainPricePerTon = 120;

    int cargoCount, currentWeight;
    
    double totalWeightByBus = 0.0;
    double totalWeightByTruck = 0.0;
    double totalWeightByTrain = 0.0;

    double totalRevenue = 0.0;
    double totalWeight = 0.0;
    double averagePricePerTon;
    double percentWeightByBus, percentWeightByTruck, percentWeightByTrain;

    cout << "Enter the count of cargo: ";
    cin >> cargoCount;

    for (int i = 0; i < cargoCount; i++) 
    {
        cin >> currentWeight;
        totalWeight += currentWeight;

        if (currentWeight <= 3) {
            totalWeightByBus += currentWeight;
            totalRevenue += currentWeight * busPricePerTon;
        } else if (currentWeight <= 11) {
            totalWeightByTruck += currentWeight;
            totalRevenue += currentWeight * truckPricePerTon;
        } else {
            totalWeightByTrain += currentWeight;
            totalRevenue += currentWeight * trainPricePerTon;
        }
    }

    averagePricePerTon = totalRevenue / totalWeight;

    percentWeightByBus = (totalWeightByBus * 100.0) / totalWeight;
    percentWeightByTruck = (totalWeightByTruck * 100.0) / totalWeight;
    percentWeightByTrain = (totalWeightByTrain * 100.0) / totalWeight;

    cout << fixed << setprecision(2);
    cout << "Total = " << averagePricePerTon << endl;
    cout << "p1 = " << percentWeightByBus << " % " << endl;
    cout << "p2 = " << percentWeightByTruck << " % " << endl;
    cout << "p3 = " << percentWeightByTrain << " % " << endl;

    return 0;
}