#include <iostream>
using namespace std;

void getScore(int& score);
void printGrade(int score);

int main()
{
    int courseScore;

    cout << "Line 8: Based on the course score, \n"
         << "this program computes the "
         << "course grade." << endl;

    getScore(courseScore);
    printGrade(courseScore);

    return 0;
}

void getScore(int& score)
{
    cout << "Line 15: Enter course score: ";
    cin >> score;
    cout << endl << "Line 17: The course score is "
         << score << endl;
}

void printGrade(int cScore)
{
    cout << "Line 21: The course grade is: ";

    if (cScore >= 90)
        cout << "A." << endl;
    else if (cScore >= 80)
        cout << "B." << endl;
    else if (cScore >= 70)
        cout << "C." << endl;
    else if (cScore >= 60)
        cout << "D." << endl;
    else
        cout << "F." << endl;
}