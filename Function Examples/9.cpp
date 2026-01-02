#include <iostream>
using namespace std;

// Function Prototype
void areaAndPerimeter(double length, double width, 
                      double& area, double& perimeter);

int main()
{
    double len, wid;
    double a, p;
    
    cout << "Enter length and width: ";
    cin >> len >> wid;
    
    // Call the function passing a and p by reference
    areaAndPerimeter(len, wid, a, p);
    
    cout << "Area: " << a << endl;
    cout << "Perimeter: " << p << endl;
    
    return 0;
}

// Function Definition from Example 6-9
void areaAndPerimeter(double length, double width, 
                      double& area, double& perimeter)
{
    area = length * width;
    perimeter = 2 * (length + width);
}