#include <iostream>
using namespace std;

int main() {
    int holidays;
    const int totalDays = 365;
    const int norm = 30000;
    const int playWorking = 63;
    const int playHoliday = 127;

    cout << "Holidays: ";
    cin >> holidays;

    int workingDays = totalDays - holidays;
    int totalPlayTime = (workingDays * playWorking) + (holidays * playHoliday);

    int difference = norm - totalPlayTime;

    if (difference >= 0) {
        cout << "Tom sleeps well" << endl;
        int hours = difference / 60;
        int minutes = difference % 60;
        cout << hours << " hours and " << minutes << " minutes less for play" << endl;
    } else {
        difference = -difference;
        cout << "Tom will run away" << endl;
        int hours = difference / 60;
        int minutes = difference % 60;
        cout << hours << " hours and " << minutes << " minutes for play" << endl;
    }

    return 0;
}
