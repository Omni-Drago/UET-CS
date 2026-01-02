#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int num;
    int guess;
    int diff;
    bool won = false;

    srand(time(0));
    num = rand() % 100; 

    cout << "I'm thinking of a number between 0 and 99." << endl;
    cout << "You have 5 tries to guess it." << endl;

    for (int tries = 1; tries <= 5; tries++) {
        cout << "Guess #" << tries << ": ";
        cin >> guess;

        diff = abs(num - guess);

        if (diff == 0) {
            won = true;
            cout << "You win!" << endl;
            break;
        } else {
            if (guess > num) {
                if (diff >= 50) {
                    cout << "Very high." << endl;
                } else if (diff >= 30) {
                    cout << "High." << endl;
                } else if (diff >= 15) {
                    cout << "Moderately high." << endl;
                } else {
                    cout << "Somewhat high." << endl;
                }
            } else {
                if (diff >= 50) {
                    cout << "Very low." << endl;
                } else if (diff >= 30) {
                    cout << "Low." << endl;
                } else if (diff >= 15) {
                    cout << "Moderately low." << endl;
                } else {
                    cout << "Somewhat low." << endl;
                }
            }
        }
    }

    if (!won) {
        cout << "You lose! The correct number was " << num << "." << endl;
    }

    return 0;
}