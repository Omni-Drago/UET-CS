#include <iostream>
using namespace std;
int main() 
{
    int num1,num2,gcd,lcm,i;

    gcd = 1;

    cout<<"Enter num1 and num2: ";
    cin>>num1>>num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Please enter positive integers.";
    }

    for (int i = 1 ; i<= num1 && i<= num2 ; ++i )
    {
        if(num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }
    
    lcm = (num1 * num2)/gcd;

    cout<<"GCD is: "<<gcd<<endl;
    cout<<"LCM is: "<<lcm<<endl;

    return 0;
}