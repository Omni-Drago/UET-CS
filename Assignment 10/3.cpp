#include <iostream>
using namespace std;
int main() {
    int number,count;       
    long long num;

    count = 0;     

    cout << "Enter a number: ";
    cin >> number;

    num = number; 

    if (num == 0) 
        count = 1;
     

    while (num > 0){ 
        num = num / 10;  
        count++;         
    }
    
    cout << "Total number of digits in " << number << " is: " << count << endl;

    return 0;
}