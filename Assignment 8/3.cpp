// Example 3-8
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int age = 0;
    int weight = 0;
    double height = 0.0;

    cout << "Line 10: Enter name, age, weight, and "
         << "height: ";
    cin >> name >> age >> weight >> height;
    cout << endl;

    cout << "Line 13: Name: " << name << endl;
    cout << "Line 14: Age: " << age << endl;
    cout << "Line 15: Weight: " << weight << endl;
    cout << "Line 16: Height: " << height << endl;
    
    return 0;
}