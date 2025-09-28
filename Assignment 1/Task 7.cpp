#include <iostream>
using namespace std;

int main()
{
    float h, s;

    cout<<"Enter time in Hours: ";
    cin>>h;

    s = h * 60 * 60;

    cout<<"Time in seconds is: "<<s;

    return 0;
}
