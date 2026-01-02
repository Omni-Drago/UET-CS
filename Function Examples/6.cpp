#include <iostream>
#include <string>
using namespace std;

// Function Prototype
bool isPalindrome(string str);

int main()
{
    string inputString;
    
    cout << "Enter a string to check if it is a palindrome: ";
    cin >> inputString;
    
    if (isPalindrome(inputString))
        cout << inputString << " is a palindrome." << endl;
    else
        cout << inputString << " is not a palindrome." << endl;
        
    return 0;
}

// Function Definition from Example 6-6
bool isPalindrome(string str)
{
    int length = str.length();

    for (int i = 0; i < length / 2; i++)
        if (str[i] != str[length - 1 - i])
            return false;

    return true;
}