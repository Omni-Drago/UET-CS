#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getStudentDetails(string names[], int ages[], float matricMarks[],
                       float fscMarks[], float ecatMarks[], int size, int &studentCount)
{
    studentCount = 0;
    string userChoice = "Yes";

    while (userChoice == "Yes" || userChoice == "yes" || userChoice == "Y" || userChoice == "y") {
        if (studentCount >= size) break;

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, names[studentCount]);

        cout << "Enter Age: ";
        cin >> ages[studentCount];
        cout << "Enter Matric Marks: ";
        cin >> matricMarks[studentCount];
        cout << "Enter FSc Marks: ";
        cin >> fscMarks[studentCount];
        cout << "Enter Ecat Marks: ";
        cin >> ecatMarks[studentCount];

        studentCount++;
        cout << "Do you want to enter another record? (Yes/No): ";
        cin >> userChoice;
    }
}

void saveToFile(string names[], int ages[], float matricMarks[],
                float fscMarks[], float ecatMarks[], int studentCount, string fileName)
{
    ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        outputFile << names[i] << ", " << ages[i] << ", " << matricMarks[i] 
                   << ", " << fscMarks[i] << ", " << ecatMarks[i] << endl;
    }
    outputFile.close();
    cout << "Data saved to " << fileName << endl;
}

int main() {
    const int MAX_SIZE = 100;
    string names[MAX_SIZE];
    int ages[MAX_SIZE];
    float matric[MAX_SIZE], fsc[MAX_SIZE], ecat[MAX_SIZE];
    int studentCount = 0;

    getStudentDetails(names, ages, matric, fsc, ecat, MAX_SIZE, studentCount);
    
    saveToFile(names, ages, matric, fsc, ecat, studentCount, "4.txt");

    return 0;
}