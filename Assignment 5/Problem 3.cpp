#include <iostream>
using namespace std;

int main() {
    float temp1,temp2,difference;

    cout<<"Enter temperature for City 1";
    cin>>temp1;

    cout<<"Enter temperature for City 2";
    cin>>temp2;

    difference = temp1 - temp2;

    if (difference < 0) {
        difference = -difference;
    }

    if (difference > 10) {
        cout << "Difference is too Big";
    }

    return 0;
}