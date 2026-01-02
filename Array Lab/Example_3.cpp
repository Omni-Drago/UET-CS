#include <iostream>
using namespace std;
int main() {
    int arr[8] = {4, 9, 15, 22, 7, 31, 11, 5};
    int search, i;

    cout<<"Find Value to Search";
    cin>>search;
    for (i = 0; i < 8; i++){
        if (search == arr[i])
            break;
            
        }

    if (search == arr[i])
        cout<< "Value is on Index: "<<i;
    else
        cout<<"Value not found";
}