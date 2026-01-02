#include <iostream>
using namespace std;

// Function Prototype
char courseGrade(int score);

int main()
{
    int score;
    
    cout << "Enter the course score (0-100): ";
    cin >> score;
    
    cout << "The grade is: " << courseGrade(score) << endl;
    
    return 0;
}

// Function Definition from Example 6-3
char courseGrade(int score)
{
    switch (score / 10)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 'F';
    case 6:
        return 'D';
    case 7:
        return 'C';
    case 8:
        return 'B';
    case 9:
    case 10:
        return 'A';
    default:
        return '?'; // Handle invalid input
    }
}