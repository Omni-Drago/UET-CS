#include <iostream>

using namespace std;

int main() {
    int i;
    int sum = 0;
    int newNum;
    double average; 

    for (i = 1; i <= 5; i++)
    {
        cin >> newNum;
        sum = sum + newNum;
    }
    average = sum / 5.0; 
    cout << "The sum is " << sum << endl;
    cout << "The average is " << average << endl;

    return 0;
}