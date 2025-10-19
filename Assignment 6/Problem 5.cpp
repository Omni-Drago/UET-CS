#include <iostream>
#include <iomanip>   
using namespace std;

int main()
{
    char serviceCode;
    double minutes, amountDue;
    double dayMinutes, nightMinutes;
    
    cout << "Enter Service Code (R/r for Regular, P/p for Premium): ";
    cin >> serviceCode;

    
    switch (serviceCode)
    {
        
        case 'r':
        case 'R':
        {
            cout << "Enter total minutes used: ";
            cin >> minutes;

            cout << "Service Type: Regular" << endl;
            cout << "Minutes Used: " << minutes << endl;

            if (minutes <= 50)
                amountDue = 10.00;   
            else
                amountDue = 10.00 + (minutes - 50) * 0.20;

            cout << fixed << setprecision(2);
            cout << "Amount Due: $" << amountDue << endl;
            break;
        }

        
        case 'p':
        case 'P':
        {
            cout << "Enter minutes used during the day: ";
            cin >> dayMinutes;

            cout << "Enter minutes used during the night: ";
            cin >> nightMinutes;

            cout << "Service Type: Premium" << endl;
            cout << "Day Minutes Used: " << dayMinutes << endl;
            cout << "Night Minutes Used: " << nightMinutes << endl;

            
            double dayCharge, nightCharge;

            if (dayMinutes <= 75)
                dayCharge = 0;
            else
                dayCharge = (dayMinutes - 75) * 0.10;

            if (nightMinutes <= 100)
                nightCharge = 0;
            else
                nightCharge = (nightMinutes - 100) * 0.05;

            amountDue = 25.00 + dayCharge + nightCharge;

            cout << fixed << setprecision(2);
            cout << "Amount Due: $" << amountDue << endl;
            break;
        }

        
        default:
            cout << "Error: Invalid Service Code Entered!" << endl;
    }

    return 0;
}
