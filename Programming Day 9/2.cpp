#include <iostream>
#include <string>
using namespace std;

int main() {
    string movies[5] = {"Gladiator", "StarWars", "Terminator", "TakingLives", "TombRider"};
    string movieName;
    int ticketPrice = 500;
    bool isFound = false;
    double finalPrice = 0;

    cout << "Available Movies: Gladiator, StarWars, Terminator, TakingLives, TombRider" << endl;
    cout << "Enter movie name: ";
    cin >> movieName;

    for (int i = 0; i < 5; i++) {
        if (movies[i] == movieName) {
            if (i % 2 != 0) {
                double discount = ticketPrice * 0.05;
                finalPrice = ticketPrice - discount;
                cout << "Odd Index (" << i << ") selected. 5% Discount applied." << endl;
            } else {
                double discount = ticketPrice * 0.10;
                finalPrice = ticketPrice - discount;
                cout << "Even Index (" << i << ") selected. 10% Discount applied." << endl;
            }

            cout << "Original Price: " << ticketPrice << endl;
            cout << "Final Price: " << finalPrice << endl;

            isFound = true;
            break;
        }
    }

    if (!isFound) {
        cout << "Sorry, that movie is not currently playing." << endl;
    }

    return 0;
}