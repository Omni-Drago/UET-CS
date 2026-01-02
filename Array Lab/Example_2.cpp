#include <iostream>
using namespace std;

int main(){
    int array[7] = {22, 15, 7, 9, 31, 31, 5};
    int n = 7;
    int large;
    int second_large;

    large=array[0];
    second_large = 0;
    for (int i = 0; i<n-1; i++ ){
        if (array[i]>large){
            second_large = large;
            large = array[i] ;
            
        }   
    }
    
    cout<<second_large;
}