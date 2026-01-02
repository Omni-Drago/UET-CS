#include <iostream>
using namespace std;
int main(){
    int i, amplify;
    
    
    cout << "Enter: "; 
    cin >> amplify;
    
    for(i = 1; i <= amplify; i++) {
        
        if(i % 4 == 0)
            cout << i * 10;
        else
            cout << i;
        
        if (i < amplify) {
            cout << ", ";
        }
    }
    
    cout << endl;
    
    return 0;
}