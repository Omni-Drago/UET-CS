#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

double parseFormattedNumber(string s) {
    string cleanStr = "";
    for(char c : s) {
        if(c != ',') cleanStr += c;
    }
    return stod(cleanStr);
}

int main() {
    const int COUNT = 20;
    vector<string> rawInputs(COUNT); 
    vector<double> values(COUNT);    
    double sum = 0;

    cout << "Please enter 20 numbers (Format like 12,32,456.65):" << endl;

    for(int i = 0; i < COUNT; i++) {
        cout << "Enter number " << (i+1) << ": ";
        cin >> rawInputs[i];
        
        values[i] = parseFormattedNumber(rawInputs[i]);
        sum += values[i];
    }

    double average = sum / COUNT;

    cout << "\n-----------------------------" << endl;
    cout << "Average Value: " << average << endl;
    cout << "-----------------------------" << endl;
    cout << "Values greater than average:" << endl;

    for(int i = 0; i < COUNT; i++) {
        if(values[i] > average) {
            cout << rawInputs[i] << endl; 
        }
    }

    return 0;
}