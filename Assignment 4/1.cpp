#include <iostream>
using namespace std;

int main() {
    double s1, s2, s3, s4, s5, avg;
    cout << "Enter five test scores: ";
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    avg = (s1 + s2 + s3 + s4 + s5) / 5.0;
    cout << "Average score = " << avg;
    return 0;
}
