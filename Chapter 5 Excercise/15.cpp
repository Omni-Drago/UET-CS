#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int num;
    int guess;
    bool won = false;

    srand(time(0));
    num = rand() % 100; 

    cout << "I'm thinking of a number between 0 and 99." << endl;
    cout << "You have 5 tries to guess it." << endl;

    for (int tries = 1; tries <= 5; tries++) {
        cout << "Guess #" << tries << ": ";
        cin >> guess;

        if (guess == num) {
            won = true;
            cout << "You win!" << endl;
            break;
        } else if (guess < num) {
            cout << "Too low." << endl;
        } else {
            cout << "Too high." << endl;
        }
    }

    if (!won) {
        cout << "You lose! The correct number was " << num << "." << endl;
    }

    return 0;
}