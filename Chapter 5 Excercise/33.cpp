#include <iostream>

using namespace std;

int main() {
    int a, b, t;
    int dishCount = 0;
    int totalTime = 0;
    int currentDishTime;

    cout << "Enter the time for the first dish (a): ";
    cin >> a;
    cout << "Enter the additional time for each dish (b): ";
    cin >> b;
    cout << "Enter the total time available (t): ";
    cin >> t;

    currentDishTime = a;

    while (totalTime + currentDishTime <= t) {
        totalTime = totalTime + currentDishTime;
        dishCount++;
        currentDishTime = currentDishTime + b;
    }

    cout << "Bianca can prepare " << dishCount << " dishes." << endl;

    return 0;
}