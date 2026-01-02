#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getStudentDetails(string names[], int admissionNumbers[], float percentages[],
                       int size, int &studentCount, string fileName)
{
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening input file!" << endl;
        return;
    }

    studentCount = 0;
    string tempName;
    int tempAdNum;
    float tempPercentage;

    while (inputFile >> tempName >> tempAdNum >> tempPercentage) {
        if (tempPercentage > 70) {
            if (studentCount < size) {
                names[studentCount] = tempName;
                admissionNumbers[studentCount] = tempAdNum;
                percentages[studentCount] = tempPercentage;
                studentCount++;
            }
        }
    }
    inputFile.close();
}

void saveToFile(string names[], int admissionNumbers[], float percentages[],
                int studentCount, string fileName)
{
    ofstream outputFile(fileName);
    for (int i = 0; i < studentCount; i++) {
        outputFile << names[i] << " " << admissionNumbers[i] << " " << percentages[i] << endl;
    }
    outputFile.close();
    cout << "Saved toppers to " << fileName << endl;
}

int main() {
    const int MAX_SIZE = 100;
    string names[MAX_SIZE];
    int adNums[MAX_SIZE];
    float percs[MAX_SIZE];
    int count = 0;

    getStudentDetails(names, adNums, percs, MAX_SIZE, count, "5.txt");
    saveToFile(names, adNums, percs, count, "5_toppers.txt");

    return 0;
}