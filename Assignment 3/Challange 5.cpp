#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name1, name2, name3;
    int age1, age2, age3;

    cout << "Enter first brother's name: ";
    cin >> name1;
    cout << "Enter " << name1 << "'s age: ";
    cin >> age1;

    cout << "Enter second brother's name: ";
    cin >> name2;
    cout << "Enter " << name2 << "'s age: ";
    cin >> age2;

    cout << "Enter third brother's name: ";
    cin >> name3;
    cout << "Enter " << name3 << "'s age: ";
    cin >> age3;

    if (age1 < age2)
    {
        if (age1 < age3)
        {
            cout << "The youngest brother is: " << name1 << endl;
        }
        else if (age3 < age1)
        {
            cout << "The youngest brother is: " << name3 << endl;
        }
        else
        {
            cout << name1 << " and " << name3 << " are the youngest (same age)." << endl;
        }
    }
    else if (age2 < age1)
    {
        if (age2 < age3)
        {
            cout << "The youngest brother is: " << name2 << endl;
        }
        else if (age3 < age2)
        {
            cout << "The youngest brother is: " << name3 << endl;
        }
        else
        {
            cout << name2 << " and " << name3 << " are the youngest (same age)." << endl;
        }
    }
    else 
    {
        if (age1 < age3)
        {
            cout << name1 << " and " << name2 << " are the youngest (same age)." << endl;
        }
        else if (age3 < age1)
        {
            cout << "The youngest brother is: " << name3 << endl;
        }
        else
        {
            cout << "All three brothers are the same age." << endl;
        }
    }

    return 0;
}
