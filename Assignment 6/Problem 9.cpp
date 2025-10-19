#include <iostream>
using namespace std;

int main()
{
    int h, x, y;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    if ((x > 0 && x < 3 * h && y > 0 && y < h) ||
        (x > h && x < 2 * h && y > h && y < 4 * h))
    {
        cout << "Inside";
    }
    else if (
        (x >= 0 && x <= 3 * h && y == 0) ||
        (x >= 0 && x <= 3 * h && y == h && !(x > h && x < 2 * h)) ||
        (x >= h && x <= 2 * h && y == 4 * h) ||
        (x == 0 && y >= 0 && y <= h) ||
        (x == 3 * h && y >= 0 && y <= h) ||
        (x == h && y >= h && y <= 4 * h) ||
        (x == 2 * h && y >= h && y <= 4 * h))
    {
        cout << "Border";
    }
    else
    {
        cout << "Outside";
    }

    return 0;
}
