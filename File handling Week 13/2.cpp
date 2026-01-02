#include <iostream>
#include <fstream>
using namespace std;

int countCharacters(string fileName);

int main() {

    string fileName = "2.txt";
    int totalCharacters = countCharacters(fileName);
    cout << "Total number of characters: " << totalCharacters << endl;
    return 0;
}

int countCharacters(string fileName) {
    ifstream inputFile(fileName);
    int charCount = 0;
    char currentCharacter;

    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 0;
    }

    while(inputFile.get(currentCharacter)) {
        charCount++;
    }

    inputFile.close();
    return charCount;
}