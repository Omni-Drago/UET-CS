// Example 2-4
#include <iostream>

using namespace std;

int main()
{
    int inches;

    inches = 100;

    cout << inches << " inch(es) = ";

    cout << inches / 12 << " feet (foot) and ";

    cout << inches % 12 << " inch(es)" << endl;
    
    return 0;
}