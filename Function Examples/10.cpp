#include <iostream>
using namespace std;

// Function Prototype
void averageAndGrade(int testScore, int progScore,
                     double& average, char& grade);

int main()
{
    int tScore, pScore;
    double avg;
    char grd;
    
    cout << "Enter test score and program score: ";
    cin >> tScore >> pScore;
    
    averageAndGrade(tScore, pScore, avg, grd);
    
    cout << "Average: " << avg << endl;
    cout << "Grade: " << grd << endl;
    
    return 0;
}

// Function Definition from Example 6-10
void averageAndGrade(int testScore, int progScore,
                     double& average, char& grade)
{
    average = (testScore + progScore) / 2.0;

    if (average >= 90.00)
        grade = 'A';
    else if (average >= 80.00)
        grade = 'B';
    else if (average >= 70.00)
        grade = 'C';
    else if (average >= 60.00)
        grade = 'D';
    else
        grade = 'F';
}