#include <iostream>
#include <string>
using namespace std;
int main()
{
    string country;

    cout<<"Enter your country: ";
    getline(cin,country);

    if (country != "Germany" && country != "Australia")
        {cout<<"You should come to visit these sometime!";}

    return 0;
}