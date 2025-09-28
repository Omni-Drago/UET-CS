#include <iostream>
#include <string>
using namespace std;

int main()
{
    float aggregate;
    int roll_number;
    char section;
    string name;

    cout << "Enter your name: ";
    cin >> name;   

    cout << "Enter your roll number: ";
    cin >> roll_number;

    cout << "Enter your aggregate: ";
    cin >> aggregate;

    cout << "Enter your section: ";
    cin >> section;

    cout << "Your name is: " << name << endl;
    cout << "Your roll number is: " << roll_number << endl;
    cout << "Your aggregate is: " << aggregate << endl;
    cout << "Your section is: " << section << endl;

    return 0;
}
