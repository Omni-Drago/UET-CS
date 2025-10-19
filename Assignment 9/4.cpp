// Corrected GPA Program
#include <iostream>

using namespace std;

int main()
{
    double gpa;

    cout << "Enter the GPA: ";
    cin >> gpa;
    cout << endl;
    
    if (gpa >= 2.0)
    {
        if (gpa >= 3.9)
            cout << "Dean's Honor List." << endl;
    }
    else
        cout << "The GPA is below the graduation "
             << "requirement. \nSee your "
             << "academic advisor." << endl;
             
    return 0;
}