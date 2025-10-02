#include <iostream>
using namespace std;

int main()
{
    int numbers[15];
    int sum = 0, product = 1, subtraction = 0, result;

    for(int i = 0; i < 15; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    for(int i = 0; i < 5; i++)
        sum += numbers[i];

    for(int i = 5; i < 10; i++)
        product *= numbers[i];

    subtraction = numbers[10];
    for(int i = 11; i < 15; i++)
        subtraction -= numbers[i];

    result = (sum + product) - subtraction;

    cout << "Final Result: " << result << endl;

    return 0;
}
