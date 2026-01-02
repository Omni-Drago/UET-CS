#include <iostream>
#include <string>
using namespace std;

int commonCharacters(string s1, string s2) {
    int count = 0;
    
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                count++;
                s2[j] = '*'; 
                break; 
            }
        }
    }
    return count;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << commonCharacters(s1, s2) << endl;

    return 0;
}