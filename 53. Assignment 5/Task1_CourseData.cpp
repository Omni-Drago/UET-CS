#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream file1("File1.txt");
    ofstream file2("File2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string code, name, status;
    int credits, semester;
    char choice = 'y';

    cout << "--- Course Data Entry ---" << endl;


    while (choice == 'y' || choice == 'Y') {
        cout << "\nEnter Course Code (e.g., MS-201): ";
        cin >> code;
        
        cout << "Enter Course Name (One word or use_underscores): ";
        cin >> name; 
        
        cout << "Enter Credit Hours: ";
        cin >> credits;
        
        cout << "Enter Semester: ";
        cin >> semester;
        
        cout << "Enter Status (active/discontinued): ";
        cin >> status;

        file1 << code << "," << name << "," << credits << "," << semester << "," << status << endl;

        file2<<code<<" "<<name<<"\t\t\t"<<credits<<" "<<semester<<status<<endl;

        cout << "Enter another course? (y/n): ";
        cin >> choice;
    }

    file1.close();
    file2.close();
    cout << "Data saved successfully." << endl;

    return 0;
}