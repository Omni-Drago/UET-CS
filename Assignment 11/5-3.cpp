#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string name;
    int numOfVolunteers;
    int numOfBoxesSold;
    int totalNumOfBoxesSold;
    int counter;
    double costOfOneBox;

    cout << fixed << showpoint << setprecision(2);

    cout << "Line 14: Enter the number of "
         << "volunteers: ";
    cin >> numOfVolunteers;
    cout << endl;

    totalNumOfBoxesSold = 0;
    counter = 0;

    while (counter < numOfVolunteers)
    {
        cout << "Line 21: Enter the volunteer's name"
             << " and the number of boxes sold: ";
        cin >> name >> numOfBoxesSold;
        cout << endl;

        totalNumOfBoxesSold = totalNumOfBoxesSold
                              + numOfBoxesSold;
        counter++;
    }

    cout << "Line 27: The total number of boxes sold: "
         << totalNumOfBoxesSold << endl;

    cout << "Line 28: Enter the cost of one box: ";
    cin >> costOfOneBox;
    cout << endl;

    cout << "Line 31: The total money made by selling "
         << "cookies: $"
         << totalNumOfBoxesSold * costOfOneBox << endl;

    if (counter != 0)
        cout << "Line 33: The average number of "
             << "boxes sold by each volunteer: "
             << totalNumOfBoxesSold / counter << endl;
    else
        cout << "Line 35: No input." << endl;

    return 0;
}