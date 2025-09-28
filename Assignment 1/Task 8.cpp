#include <iostream>
using namespace std;

int main()
{
    float P, V, I;

    cout<<"Enter Value of Voltage(V): ";
    cin>>V;
    
    cout<<"Enter Value of Current(A): ";
    cin>>I;

    P = V * I;

    cout<<"Power is: "<<P;

    return 0;
}
