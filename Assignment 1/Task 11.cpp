#include <iostream>
using namespace std;

int main()
{
    int population,n,total_population;

    cout<<"Enter Population: ";
    cin>>population;

    cout<<"Enter monthly birth rates: ";
    cin>>n;

    total_population = population + (n*12*30);

    cout<<"Total Population after 3 decades is: "<<total_population;

    return 0;
}

