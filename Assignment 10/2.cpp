#include <iostream>
using namespace std;
int main() {
    
    int length, t1, t2, NextTerm;
    t1 = 0;
    t2 = 1;
    NextTerm = 0;

    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> length;

    cout << "Fibonacci Series: ";
    
    for (int i = 1; i <= length; ++i) {
        
        if (i == 1) 
            cout << t1 << ", ";
        
        if (i == 2) 
            cout << t2 << ", ";
               
        NextTerm = t1 + t2;

        t1 = t2;
        t2 = NextTerm;
        
        cout << NextTerm << ", ";
    }
    
    return 0;
}