#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string convertTwoDigits(int n) {
    if (n < 20) return ones[n];
    string s = tens[n / 10];
    if (n % 10 > 0) s += " " + ones[n % 10];
    return s;
}

string convertToWords(long long n) {
    if (n == 0) return "";
    
    string result = "";

    if (n >= 10000000) {
        result += convertTwoDigits(n / 10000000) + " Crore ";
        n %= 10000000;
    }
    
    if (n >= 100000) {
        result += convertTwoDigits(n / 100000) + " Lac ";
        n %= 100000;
    }

    if (n >= 1000) {
        result += convertTwoDigits(n / 1000) + " Thousand ";
        n %= 1000;
    }

    if (n >= 100) {
        result += convertTwoDigits(n / 100) + " Hundred ";
        n %= 100;
    }

    if (n > 0) {
        if (result != "") result += "and ";
        result += convertTwoDigits(n);
    }
    
    return result;
}

int main() {
    const int SIZE = 20;
    string inputs[SIZE];
    
    cout << "Enter 20 numbers (Format: 12,32,456.65): " << endl;
    
    for(int i=0; i<SIZE; i++) {
        cin >> inputs[i];
    }

    cout << "\n--- Output in Words ---" << endl;

    for(int i=0; i<SIZE; i++) {
        string s = inputs[i];
        
        string cleanStr = "";
        for(char c : s) if(c != ',') cleanStr += c;

        long long integerPart = 0;
        int decimalPart = 0;
        
        size_t decimalPos = cleanStr.find('.');
        if (decimalPos != string::npos) {
            integerPart = stoll(cleanStr.substr(0, decimalPos));
            string decStr = cleanStr.substr(decimalPos + 1);
            if(decStr.length() > 2) decStr = decStr.substr(0, 2); 
            if(decStr.length() == 1) decStr += "0"; 
            decimalPart = stoi(decStr);
        } else {
            integerPart = stoll(cleanStr);
        }

        cout << "\nInput: " << s << endl;
        cout << "Words: " << convertToWords(integerPart) << " Rupees";
        
        if (decimalPart > 0) {
            cout << " and " << convertTwoDigits(decimalPart) << " Paisas";
        }
        cout << endl;
    }

    return 0;
}