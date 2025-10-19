#include <iostream>

using namespace std;

int main() {
    int counter;
    int nthFibonacci;
    int current;
    int previous1;
    int previous2;

    previous1 = 1;
    previous2 = 1;
    nthFibonacci = 10; 

    if (nthFibonacci == 1) {
        current = previous1;
    } else if (nthFibonacci == 2) {
        current = previous2;
    } else {
        for (counter = 3; counter <= nthFibonacci; counter++)
        {
            current = previous2 + previous1;
            previous1 = previous2;
            previous2 = current;
        }
    }

    cout << "The " << nthFibonacci << "th Fibonacci number is: " << current << endl;

    return 0;
}

