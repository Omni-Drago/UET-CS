#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int countLines(string fileName);

int main() {

    string fileName = "1.txt";
    int totalLines = countLines(fileName);

    cout << "Total number of lines: " << totalLines << endl;

    return 0;
}

int countLines(string fileName) {
    ifstream inputFile(fileName);
    int lineCount = 0;
    string currentLine;

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return 0;
    }

    while (getline(inputFile, currentLine)) {
        lineCount++;
    }

    inputFile.close();
    return lineCount;
}