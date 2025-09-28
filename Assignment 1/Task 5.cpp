#include <iostream>
using namespace std;

int main()
{
    float matric, intermediate, ECAT, aggregate;

    cout<<"Enter matric number(out of 1100): ";
    cin>>matric;

    cout<<"Enter intermediate number(out of 550): ";
    cin>>intermediate;

    cout<<"Enter ECAT number(out of 400): ";
    cin>>ECAT;

    aggregate = (matric/1100 * 0.10 + intermediate/550 * 0.40 + ECAT/400 * 0.50) * 100;
    cout<<"aggregate = "<<aggregate;

    return 0;
}
