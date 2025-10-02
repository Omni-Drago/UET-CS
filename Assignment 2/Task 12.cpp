#include <iostream>
using namespace std;

int main()
{
    int n, w, h, walls;

    cout << "Enter paint area (in sq meters): ";
    cin >> n;

    cout << "Enter wall width (in meters): ";
    cin >> w;

    cout << "Enter wall height (in meters): ";
    cin >> h;

    walls = n / (w * h);

    cout << "Number of complete walls that can be painted: " << walls << endl;

    return 0;
}
