#include <iostream>
#include <iomanip>

using namespace std;

//Named constants residential customers
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;

//Named constants business customers
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;

double residential(); //Function prototype
double business();    //Function prototype

int main()
{
    //declare variables
    int accountNumber;
    char customerType;
    double amountDue;

    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "This program computes a cable bill." << endl;

    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << endl;

    cout << "Enter customer type: R, r (Residential), "
         << "B, b (Business): ";
    cin >> customerType;
    cout << endl;

    switch (customerType)
    {
    case 'r':
    case 'R':
        amountDue = residential();
        cout << "Account number = " << accountNumber << endl;
        cout << "Amount due = $" << amountDue << endl;
        break;

    case 'b':
    case 'B':
        amountDue = business();
        cout << "Account number = " << accountNumber << endl;
        cout << "Amount due = $" << amountDue << endl;
        break;

    default:
        cout << "Invalid customer type." << endl;
    }

    return 0;
}

double residential()
{
    int noOfPChannels;
    double bAmount;

    cout << "Enter the number of premium channels used: ";
    cin >> noOfPChannels;
    cout << endl;

    bAmount = RES_BILL_PROC_FEES + RES_BASIC_SERV_COST +
              noOfPChannels * RES_COST_PREM_CHANNEL;

    return bAmount;
}

double business()
{
    int noOfBasicServiceConnections;
    int noOfPChannels;
    double bAmount;

    cout << "Enter the number of basic service connections: ";
    cin >> noOfBasicServiceConnections;
    cout << endl;

    cout << "Enter the number of premium channels used: ";
    cin >> noOfPChannels;
    cout << endl;

    if (noOfBasicServiceConnections <= 10)
        bAmount = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST +
                  noOfPChannels * BUS_COST_PREM_CHANNEL;
    else
        bAmount = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST +
                  (noOfBasicServiceConnections - 10) *
                      BUS_BASIC_CONN_COST +
                  noOfPChannels * BUS_COST_PREM_CHANNEL;

    return bAmount;
}