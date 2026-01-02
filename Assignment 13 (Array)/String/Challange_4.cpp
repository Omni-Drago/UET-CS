#include <iostream>
#include <string>

int main() {
    using namespace std;

    string s2;
    int vowelCount = 0;
    cout << "Challenge 4 Input: ";
    cin >> s2;

    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u' ||
            s2[i] == 'A' || s2[i] == 'E' || s2[i] == 'I' || s2[i] == 'O' || s2[i] == 'U') {
            vowelCount++;
        }
    }
    cout << "Challenge 4 Output: " << vowelCount << endl;

    return 0;
}