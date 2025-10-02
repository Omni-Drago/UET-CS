#include <iostream>
using namespace std;

int main()
{
    double bagSize, bagCost, area, costPerPound, costPerSquareFoot;

    cout << "Enter the size of the fertilizer bag (in pounds): ";
    cin >> bagSize;

    cout << "Enter the cost of the bag: ";
    cin >> bagCost;

    cout << "Enter the area covered by the bag (in square feet): ";
    cin >> area;

    costPerPound = bagCost / bagSize;
    costPerSquareFoot = bagCost / area;

    cout << "Cost of fertilizer per pound: " << costPerPound << endl;
    cout << "Cost of fertilizing per square foot: " << costPerSquareFoot << endl;

    return 0;
}
