#include <iostream>
using namespace std;

double getRadius();
double circleArea(double radius);

int main()
{
    double r = getRadius();
    double area = circleArea(r);
    cout << "Area: " << area << endl;
    return 0;
}

double getRadius()
{
    double r;
    cout << "Enter Radius: ";
    cin >> r;
    return r;
}

double circleArea(double radius)
{
    double area = 3.14159 * radius * radius;
    return area;
}