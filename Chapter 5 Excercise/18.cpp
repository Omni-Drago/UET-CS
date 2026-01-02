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

    cout << fixed << showpoint << setprecision(2);

    cin >> costOfOneBox;

    totalNumOfBoxesSold = 0;
    numOfVolunteers = 0;

    while (cin >> name) {
        cin >> numOfBoxesSold;
        totalNumOfBoxesSold = totalNumOfBoxesSold + numOfBoxesSold;
        numOfVolunteers++;
    }

    cout << endl;
    cout << "The total number of boxes sold: "
         << totalNumOfBoxesSold << endl;

    cout << "The total money made by selling cookies: $"
         << totalNumOfBoxesSold * costOfOneBox << endl;

    if (numOfVolunteers != 0)
        cout << "The average number of boxes sold by each volunteer: "
             << totalNumOfBoxesSold / numOfVolunteers
             << endl;
    else
        cout << "No data processed." << endl;

    return 0;
}