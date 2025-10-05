#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string figureType;
    double side = 0, length = 0, width = 0, radius = 0, base = 0, height = 0, area = 0;

    cout << "Enter figure type (square, rectangle, circle, triangle): ";
    cin >> figureType;

    if (figureType == "square") {
        cin >> side;
        area = side * side;
    }
    else if (figureType == "rectangle") {
        cin >> length >> width;
        area = length * width;
    }
    else if (figureType == "circle") {
        cin >> radius;
        area = M_PI * radius * radius;
    }
    else if (figureType == "triangle") {
        cin >> base >> height;
        area = 0.5 * base * height;
    }
    else {
        cout << "Invalid figure type!" << endl;
    }

    if (area > 0) {
        cout << area << endl;
    }

    return 0;
}
