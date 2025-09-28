#include <iostream>
using namespace std;

int main()
{
    float MB, KB, Bytes, bits;

    cout<<"Enter Size in MB";
    cin>>MB;

    KB = MB * 1024;

    Bytes = KB * 1024;

    bits = Bytes * 8;

    cout<< "MB converted to bits is: " <<bits;

    return 0;
}
