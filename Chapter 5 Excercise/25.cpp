#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int counter;
    int num;
    int sum;

    ifstream infile;
    infile.open("data.txt");

    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    counter = 0;
    infile >> num;
    while (infile)
    {
        sum = 0;
        while (num != -999)
        {
            sum = sum + num;
            infile >> num;
        }
        counter++;
        cout << "Line " << counter
             << ": Sum = " << sum << endl;
        infile >> num;
    }

    infile.close();

    return 0;
}