#include <iostream>
using namespace std;
int main() 
{
    int n, current_number, i;
    double count_p1 = 0; 
    double count_p2 = 0; 
    double count_p3 = 0; 
    double count_p4 = 0; 
    double count_p5 = 0; 
    double p1,p2,p3,p4,p5;
    

    cout << "Enter the total count of numbers (n): ";
    cin >> n;

    cout << "Enter the " << n << " numbers, one per line:" << endl;
    for (i = 0; i < n; ++i) {
        cin >> current_number;

        if (current_number < 200) {
            count_p1++;
        } else if (current_number >= 200 && current_number <= 399) {
            count_p2++;
        } else if (current_number >= 400 && current_number <= 599) {
            count_p3++;
        } else if (current_number >= 600 && current_number <= 799) {
            count_p4++;
        } else { 
            count_p5++;
        }
    }

    p1 = (count_p1 / n) * 100.0;
    p2 = (count_p2 / n) * 100.0;
    p3 = (count_p3 / n) * 100.0;
    p4 = (count_p4 / n) * 100.0;
    p5 = (count_p5 / n) * 100.0;

    cout << "Results" << endl;
    
    cout << fixed;

    cout << p1 << "%" << endl;
    cout << p2 << "%" << endl;
    cout << p3 << "%" << endl;
    cout << p4 << "%" << endl;
    cout << p5 << "%" << endl;

    return 0;

}