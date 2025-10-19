#include <iostream>
using namespace std;
int main() 
{
    int count,sum,last_digit;
    long long num,number;

    cout<< "Enter the number; ";
    cin>>number;

    sum = 0;
    num = number;

    if (num == 0){
            sum = 0;
        
    }
    
    while (num >0){
        last_digit = num % 10; 

        sum = sum + last_digit;
        
        num = num/10;
    }

    cout << "The sum of the digits in " << number << " is: " << sum << endl;
    return 0;
}