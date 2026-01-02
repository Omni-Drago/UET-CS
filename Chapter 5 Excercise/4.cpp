#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string inputLine;
    string continueResponse;

    do {
        cout << "Enter a telephone number expressed in letters: ";
        getline(cin, inputLine);

        int letterCount = 0;
        cout << "The corresponding number is: ";

        for (char c : inputLine) {
            
            if (isalpha(c)) {
                
                letterCount++;

                char upperLetter = toupper(c);

                switch (upperLetter) {
                    case 'A': case 'B': case 'C':
                        cout << 2;
                        break;
                    case 'D': case 'E': case 'F':
                        cout << 3;
                        break;
                    case 'G': case 'H': case 'I':
                        cout << 4;
                        break;
                    case 'J': case 'K': case 'L':
                        cout << 5;
                        break;
                    case 'M': case 'N': case 'O':
                        cout << 6;
                        break;
                    case 'P': case 'Q': case 'R': case 'S':
                        cout << 7;
                        break;
                    case 'T': case 'U': case 'V':
                        cout << 8;
                        break;
                    case 'W': case 'X': case 'Y': case 'Z':
                        cout << 9;
                        break;
                }

                if (letterCount == 3) {
                    cout << "-";
                }

                if (letterCount == 7) {
                    break;
                }
            }
        }

        cout << endl << endl;

        cout << "Process another telephone number? (y/n): ";
        getline(cin, continueResponse);

    } while (!continueResponse.empty() && (continueResponse[0] == 'y' || continueResponse[0] == 'Y'));

    cout << "Goodbye!" << endl;

    return 0;
}