#include <iostream>
using namespace std;

int main(){
    int array[6] = {34, 12, 9, 56, 2, 17};

    int n = 6;

    for (int i = 0; i<n-1; i++ ){
        for (int j = 0; j < n-i-1; j++)
        {
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        
    }

    cout<<"Array after sorting ";
    for (int i = 0; i<n;i++)
        cout<<array[i]<<"  ";
    return 0;
    
}