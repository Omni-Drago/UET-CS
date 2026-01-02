#include <iostream>
using namespace std;
int main(){

    int number[]={4,6,7,8,9,20};
    int sum = 0;

    double average;
    cout<<"the numbers are: "<<endl;
    for (int i = 0; i<6; i++)
    {
        cout<<number[i]<< " ";
        sum = sum + number[i];
    }

    cout<<"\n their sum= "<<sum<<endl;
    average = sum/6.0;
    cout<<"Their average ="<<average<<endl;

}

