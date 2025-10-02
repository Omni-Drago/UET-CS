#include <iostream>
using namespace std;

int main()
{
    string movie;
    double adultPrice, childPrice, total, donation, remaining;
    int adultTickets, childTickets;
    double percent;

    cout << "Enter movie name: ";
    cin >> movie;

    cout << "Enter adult ticket price: ";
    cin >> adultPrice;

    cout << "Enter child ticket price: ";
    cin >> childPrice;

    cout << "Enter number of adult tickets sold: ";
    cin >> adultTickets;

    cout << "Enter number of child tickets sold: ";
    cin >> childTickets;

    cout << "Enter percentage to be donated: ";
    cin >> percent;

    total = (adultPrice * adultTickets) + (childPrice * childTickets);
    donation = total * (percent / 100);
    remaining = total - donation;

    cout << "Total amount generated: " << total << endl;
    cout << "Donation to charity: " << donation << endl;
    cout << "Remaining amount: " << remaining << endl;

    return 0;
}
