#include <iostream>
#include <string>
using namespace std;

int main()
{
    float s1, s2, s3, s4, s5, total, percentage;
    string Name;

    cout << "Enter your name: ";
    getline(cin, Name);
    cout << "Name is: " << Name << endl;

    cout << "Enter Marks of Five Subjects (Out of 100): " << endl;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;

    total = s1 + s2 + s3 + s4 + s5;
    cout << "Total = " << total << endl;

    percentage = (total / 500) * 100;
    cout << "Percentage is: " << percentage << "%" << endl;

    if (percentage >= 90 && percentage <= 100)
        cout << "Grade: A+";
    else if (percentage >= 80 && percentage < 90)
        cout << "Grade: A";
    else if (percentage >= 70 && percentage < 80)
        cout << "Grade: B+";
    else if (percentage >= 60 && percentage < 70)
        cout << "Grade: B";
    else if (percentage >= 50 && percentage < 60)
        cout << "Grade: C";
    else if (percentage >= 40 && percentage < 50)
        cout << "Grade: D";
    else
        cout << "Grade: F";

    return 0;
}
