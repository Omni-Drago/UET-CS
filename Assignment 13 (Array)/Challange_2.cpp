#include <iostream>
using namespace std;
int main(){
    int size = 10;
    int numbers[size];

    for(int i = 0; i < size; i++){
        cout<<"Enter Numbers"<<endl;
        cin>>numbers[i];
    }

    int smallest = numbers[0];
    for(int i = 1; i<size ; ++i)
        if (numbers[i]<smallest)
        {
            smallest = numbers[i];
        }
        

    cout<<"The Smallest Element is: "<<smallest;
    return 0;
}