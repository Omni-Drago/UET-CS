#include <iostream>
using namespace std;

int main()
{
    float initialVelocity, acceleration, time, finalVelocity;

    cout << "Enter Initial Velocity (u): ";
    cin >> initialVelocity;

    cout << "Enter Acceleration (a): ";
    cin >> acceleration;

    cout << "Enter Time (t): ";
    cin >> time;

    finalVelocity = initialVelocity + (acceleration * time);

    cout << "Final Velocity (v) of the car is: " << finalVelocity << endl;

    return 0;
}
