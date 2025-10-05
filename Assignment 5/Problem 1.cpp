#include <iostream>
#include <string>
using namespace std;

int main() {
    string country;
    double ticketPrice, discount = 0.0, finalPrice;

    cout << "Enter Country Name: ";
    getline(cin, country); 

    cout << "Enter Ticket Price in Dollars: ";
    cin >> ticketPrice;

    
    if (country == "Ireland" || country == "ireland" || country == "IRELAND") {
        discount = 0.10; 
    } else {
        discount = 0.05; 
    }

    finalPrice = ticketPrice - (ticketPrice * discount);

    cout << "Final Ticket Price after Discount: $" << finalPrice << endl;

    return 0;
}
