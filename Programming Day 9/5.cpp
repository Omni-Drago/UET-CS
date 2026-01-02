#include <iostream>
#include <string>
using namespace std;

bool testJackpot(string arr[4]) {
    for (int i = 1; i < 4; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    string slot1[4] = {"@", "@", "@", "@"};
    string slot2[4] = {"&&", "&", "&&&", "&&&&"};
    string slot3[4] = {"SS", "SS", "SS", "Ss"};

    cout << boolalpha << testJackpot(slot1) << endl;
    cout << boolalpha << testJackpot(slot2) << endl;
    cout << boolalpha << testJackpot(slot3) << endl;

    return 0;
}