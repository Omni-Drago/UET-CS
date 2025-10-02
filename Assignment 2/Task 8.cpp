#include <iostream>
using namespace std;

int main()
{
    double vegPrice, fruitPrice, earningsCoins, earningsRps;
    int vegKg, fruitKg;

    cout << "Enter vegetable price per kilogram: ";
    cin >> vegPrice;

    cout << "Enter fruit price per kilogram: ";
    cin >> fruitPrice;

    cout << "Enter total kilograms of vegetables: ";
    cin >> vegKg;

    cout << "Enter total kilograms of fruits: ";
    cin >> fruitKg;

    earningsCoins = (vegPrice * vegKg) + (fruitPrice * fruitKg);
    earningsRps = earningsCoins / 1.94;

    cout << "Total earnings in Rps: " << earningsRps << endl;

    return 0;
}


