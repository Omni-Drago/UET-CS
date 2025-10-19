#include <iostream>
using namespace std;
int main(){
    
    int i,product,num;
    cout<<"Enter Number: "<<endl;
    cin>>num;

    for (i = 1; i<=10; i++)
        {product = num * i;
        cout<<num<<" X "<<i<<" = "<<product<<endl;}

    return 0;

}