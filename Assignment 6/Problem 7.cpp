#include <iostream>
#include <string>
using namespace std;

int main()
{
    string month;
    int stays;
    double studio, apartment;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter number of stays: ";
    cin >> stays;

    if (month == "May" || month == "October")
    {
        studio = 50 * stays;
        apartment = 65 * stays;

        if (stays > 14)
        {
            studio = studio - (studio * 0.30);
            apartment = apartment - (apartment * 0.10);
        }
        else if (stays > 7)
        {
            studio = studio - (studio * 0.05);
        }
    }
    else if (month == "June" || month == "September")
    {
        studio = 75.20 * stays;
        apartment = 68.70 * stays;

        if (stays > 14)
        {
            studio = studio - (studio * 0.20);
            apartment = apartment - (apartment * 0.10);
        }
    }
    else if (month == "July" || month == "August")
    {
        studio = 76 * stays;
        apartment = 77 * stays;

        if (stays > 14)
        {
            apartment = apartment - (apartment * 0.10);
        }
    }
    else
    {
        cout << "error";
    }

    if (month == "May" || month == "October" || month == "June" || month == "September" || month == "July" || month == "August")
    {
        cout << "Apartment: " << apartment << "$." << endl;
        cout << "Studio: " << studio << "$.";
    }

    return 0;
}
