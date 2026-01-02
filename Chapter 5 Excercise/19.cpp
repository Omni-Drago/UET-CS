#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string name;
    int numOfVolunteers;
    int numOfBoxesSold;
    int totalNumOfBoxesSold;
    double costOfOneBox;

    int maxBoxesSold = 0;
    string topSellers = "";

    cout << fixed << showpoint << setprecision(2);

    cin >> costOfOneBox;

    totalNumOfBoxesSold = 0;
    numOfVolunteers = 0;

    while (cin >> name) {
        cin >> numOfBoxesSold;
        totalNumOfBoxesSold = totalNumOfBoxesSold + numOfBoxesSold;
        numOfVolunteers++;

        if (numOfBoxesSold > maxBoxesSold) {
            maxBoxesSold = numOfBoxesSold;
            topSellers = name + " ";
        } else if (numOfBoxesSold == maxBoxesSold) {
            topSellers = topSellers + name + " ";
        }
    }

    cout << endl;
    cout << "The total number of boxes sold: "
         << totalNumOfBoxesSold << endl;

    cout << "The total money made by selling cookies: $"
         << totalNumOfBoxesSold * costOfOneBox << endl;

    if (numOfVolunteers != 0) {
        cout << "The average number of boxes sold by each volunteer: "
             << totalNumOfBoxesSold / numOfVolunteers
             << endl;

        double donation = (maxBoxesSold * costOfOneBox) * 0.10;
        
        cout << endl;
        cout << "Top Seller(s): " << topSellers << endl;
        cout << "The donation amount is: $" << donation << endl;
    } else {
        cout << "No data processed." << endl;
    }

    return 0;
}