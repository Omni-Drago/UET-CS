#include <iostream>
#include <cctype> 

using namespace std;

int main() {
    char letter;

    cout << "Enter a single letter: ";
    cin >> letter;

    if (isalpha(letter)) {
        char upperLetter = toupper(letter);

        cout << "The corresponding digit is: ";

        switch (upperLetter) {
            case 'A':
            case 'B':
            case 'C':
                cout << 2 << endl;
                break;
            case 'D':
            case 'E':
            case 'F':
                cout << 3 << endl;
                break;
            case 'G':
            case 'H':
            case 'I':
                cout << 4 << endl;
                break;
            case 'J':
            case 'K':
            case 'L':
                cout << 5 << endl;
                break;
            case 'M':
            case 'N':
            case 'O':
                cout << 6 << endl;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                cout << 7 << endl;
                break;
            case 'T':
            case 'U':
            case 'V':
                cout << 8 << endl;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                cout << 9 << endl;
                break;
        }
    } else {
        cout << "Error: Invalid input. Please enter a letter from A-Z." << endl;
    }

    return 0;
}