#include <iostream>
#include <string>
using namespace std;

bool checkStringLength(string word);

int main() {
    string input;

    cout << "Enter a String: ";
    cin >> input;

    bool result = checkStringLength(input);

    cout << boolalpha << result << endl;

    return 0;
}

bool checkStringLength(string word) {
    if (word.length() % 2 == 0) {
        return true;
    } else {
        return false;
    }
}