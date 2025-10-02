#include <iostream>
using namespace std;

int main()
{
    int imposters, players;
    double chance;

    cout << "Enter number of imposters: ";
    cin >> imposters;

    cout << "Enter number of players: ";
    cin >> players;

    chance = 100.0 * imposters / players;

    int roundedChance = chance + 0.5;  // manual rounding

    cout << "Chance of being an imposter: " << roundedChance << "%" << endl;

    return 0;
}
