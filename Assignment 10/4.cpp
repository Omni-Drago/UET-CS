#include <iostream>
using namespace std;
int main() 
{
    int count,digit_to_find,last_digit;
    long long num;

    count = 0;

    cout<< "Enter the number; ";
    cin>>num;

    cout<<"Enter a digit you want to find from 0 to 9: ";
    cin>>digit_to_find;

    if (num == 0){
        if (digit_to_find == 0)
            count = 1;
        
    }
    
    while (num >0){
        last_digit = num % 10; 

        if (last_digit == digit_to_find)
            count++;
        
        num = num/10;
    }

    cout << "The digit " << digit_to_find << " appears " << count << " times in " << num;

    return 0;
}