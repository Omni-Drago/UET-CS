#include <iostream>
#include <string>
using namespace std;

int main()
{
    string temperature, humidity;
    
    cout << "Enter temperature (warm or cold): ";
    cin >> temperature;
    
    cout << "Enter humidity (dry or humid): ";
    cin >> humidity;
    
    if (temperature == "warm")
    {
        if (humidity == "dry")
            cout << "Play Tennis";
        else if (humidity == "humid")
            cout << "Swim";
    }
    else if (temperature == "cold")
    {
        if (humidity == "dry")
            cout << "Play Basketball";
        else if (humidity == "humid")
            cout << "Watch TV";
    }

    return 0;
}
