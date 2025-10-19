#include <iostream>
using namespace std;

int main()
{
    int examHour, examMin, arrivalHour, arrivalMin;
    int examTime, arrivalTime, diff, hours, minutes;

    cout << "Exam Starting Time (hour): ";
    cin >> examHour;
    cout << "Exam Starting Time (minutes): ";
    cin >> examMin;
    cout << "Student hour of arrival: ";
    cin >> arrivalHour;
    cout << "Student minutes of arrival: ";
    cin >> arrivalMin;

    examTime = examHour * 60 + examMin;
    arrivalTime = arrivalHour * 60 + arrivalMin;
    diff = arrivalTime - examTime;

    if (diff > 0)
    {
        cout << "Late" << endl;

        if (diff < 60)
            cout << diff << " minutes after the start";
        else
        {
            hours = diff / 60;
            minutes = diff % 60;
            cout << hours << ":" << minutes << " hours after the start";
        }
    }
    else if (diff <= 0 && diff >= -30)
    {
        cout << "On time" << endl;

        if (diff != 0)
            cout << -diff << " minutes before the start";
    }
    else
    {
        cout << "Early" << endl;

        diff = -diff;
        if (diff < 60)
            cout << diff << " minutes before the start";
        else
        {
            hours = diff / 60;
            minutes = diff % 60;
            cout << hours << ":" << minutes << " hours before the start";
        }
    }

    return 0;
}
