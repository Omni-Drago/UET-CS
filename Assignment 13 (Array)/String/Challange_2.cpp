#include <iostream>
#include <string>

int main() {
    using namespace std;

    string s1;
    cout << "Challenge 2 Input: ";
    cin >> s1;

    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == 'z') {
            s1[i] = 'a';
        } else if (s1[i] == 'Z') {
            s1[i] = 'A';
        } else if ((s1[i] >= 'a' && s1[i] < 'z') || (s1[i] >= 'A' && s1[i] < 'Z')) {
            s1[i] = s1[i] + 1;
        }
    }
    cout << "Challenge 2 Output: " << s1 << endl;

    return 0;
}