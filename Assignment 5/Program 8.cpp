#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    cout << "Enter a number (0–100): ";
    cin >> number;

    string ones[] = {"zero", "one", "two", "three", "four", "five", "six",
                     "seven", "eight", "nine", "ten", "eleven", "twelve",
                     "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                     "eighteen", "nineteen"};

    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty",
                     "sixty", "seventy", "eighty", "ninety"};

    if (number < 0 || number > 100) {
        cout << "Number out of range!" << endl;
    }
    else if (number < 20) {
        cout << ones[number] << endl;
    }
    else if (number < 100) {
        int t = number / 10;
        int o = number % 10;

        cout << tens[t];
        if (o != 0)
            cout << " " << ones[o];
        cout << endl;
    }
    else if (number == 100) {
        cout << "one hundred" << endl;
    }

    return 0;
}
