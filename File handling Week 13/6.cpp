#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int countLines(string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    char forbiddenChar;
    inputFile >> forbiddenChar; 
    forbiddenChar = tolower(forbiddenChar);
    inputFile.ignore();

    int validLines = 0;
    string currentLine;

    while (getline(inputFile, currentLine)) {
        int i = 0;
        
        while (i < currentLine.length() && currentLine[i] == ' ') i++;

        
        if (i == currentLine.length() || tolower(currentLine[i]) != forbiddenChar) {
            validLines++;
        }
    }
    inputFile.close();
    return validLines;
}

int main() {
    
    cout << "Count: " << countLines("6.txt") << endl;
    return 0;
}