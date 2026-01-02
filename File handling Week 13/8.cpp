#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int calculateFrequency(string fileName);

int main() {

    string fileName = "3.txt";
    int frequency = calculateFrequency(fileName);
    cout << "Frequency: " << frequency << endl;
    return 0;
}

int calculateFrequency(string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    char targetCharacter;
    inputFile >> targetCharacter; 
    targetCharacter = tolower(targetCharacter);

    inputFile.ignore(); 

    int frequencyCount = 0;
    char currentCharacter;

    while (inputFile.get(currentCharacter)) {
        if (tolower(currentCharacter) == targetCharacter) {
            frequencyCount++;
        }
    }

    inputFile.close();
    return frequencyCount;
}