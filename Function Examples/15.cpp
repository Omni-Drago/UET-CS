#include <iostream>
using namespace std;

void addFirst(int& first, int& second);
void doubleFirst(int one, int two);
void squareFirst(int& ref, int val);

int main()
{
    int num = 5;

    cout << "Line 9: Inside main: num = " << num
         << endl;

    addFirst(num, num);

    cout << "Line 11: Inside main after addFirst: "
         << "num = " << num << endl;

    doubleFirst(num, num);

    cout << "Line 13: Inside main after "
         << "doubleFirst: num = " << num << endl;

    squareFirst(num, num);

    cout << "Line 15: Inside main after "
         << "squareFirst: num = " << num << endl;

    return 0;
}

void addFirst(int& first, int& second)
{
    cout << "Line 20: Inside addFirst: first = "
         << first << ", second = " << second << endl;

    first = first + 2;

    cout << "Line 22: Inside addFirst: first = "
         << first << ", second = " << second << endl;

    second = second * 2;

    cout << "Line 24: Inside addFirst: first = "
         << first << ", second = " << second << endl;
}

void doubleFirst(int one, int two)
{
    cout << "Line 28: Inside doubleFirst: one = "
         << one << ", two = " << two << endl;

    one = one * 2;

    cout << "Line 30: Inside doubleFirst: one = "
         << one << ", two = " << two << endl;

    two = two + 2;

    cout << "Line 32: Inside doubleFirst: one = "
         << one << ", two = " << two << endl;
}

void squareFirst(int& ref, int val)
{
    cout << "Line 36: Inside squareFirst: ref = "
         << ref << ", val = " << val << endl;

    ref = ref * ref;

    cout << "Line 38: Inside squareFirst: ref = "
         << ref << ", val = " << val << endl;

    val = val + 2;

    cout << "Line 40: Inside squareFirst: ref = "
         << ref << ", val = " << val << endl;
}