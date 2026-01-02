#include <iostream>
using namespace std;
int main(){
    int size = 10;
    int numbers[size];

    for(int i = 0; i < size; i++){
        cout<<"Enter Numbers"<<endl;
        cin>>numbers[i];
    }

    cout<<"Numbers in reverse order are: "<<endl;
    for(int j = 9; j>= 0; j--)
        cout<<numbers[j]<<" ";

    cout<<endl;
    return 0;
}