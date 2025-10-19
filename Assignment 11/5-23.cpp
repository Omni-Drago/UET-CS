#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int counter;
    int sum;
    int num;

    ifstream infile;
    infile.open("data.txt");

    if (!infile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    counter = 0;
    while (counter < 5)
    {
        sum = 0;
        infile >> num;
        while (num != -999)
        {
            sum = sum + num;
            infile >> num;
        }
        cout << "Line " << counter + 1
             << ": Sum = " << sum << endl;
        counter++;
    }

    infile.close();

    return 0;
}