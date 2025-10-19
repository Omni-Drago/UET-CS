// Example 2-13 & 2-18
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num1, num2;
    double sale;
    char first;
    string str;

    num1 = 4;
    cout << "num1 = " << num1 << endl;

    num2 = 4 * 5 - 11;
    cout << "num2 = " << num2 << endl;

    sale = 0.02 * 1000;
    cout << "sale = " << sale << endl;

    first = 'D';
    cout << "first = " << first << endl;

    str = "It is a sunny day.";
    cout << "str = " << str << endl;

    string firstName;
    string lastName;
    int age;
    double weight;

    cout << "\nEnter first name, last name, age, "
         << "and weight, separated by spaces."
         << endl;

    cin >> firstName >> lastName;
    cin >> age >> weight;

    cout << "\nName: " << firstName << " "
         << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;

    return 0;
}