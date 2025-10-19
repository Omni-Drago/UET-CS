#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream infile;
    int ID;
    char ch;
    string name;
    int sum;
    int num;

    infile.open("data.txt");

    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    infile >> ID;
    while (infile)
    {
        infile.get(ch);
        getline(infile, name);
        sum = 0;
        infile >> num;
        while (num != -999)
        {
            sum = sum + num;
            infile >> num;
        }
        cout << "Name: " << name
             << ", Votes: " << sum << endl;
        infile >> ID;
    }

    infile.close();

    return 0;
}