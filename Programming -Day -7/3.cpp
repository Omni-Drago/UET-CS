#include <iostream>

int main() {
    using namespace std;

    int period;
    int patient;
    int treated = 0;
    int untreated = 0;
    int doctors = 7;

    cout << "Enter the period: ";
    cin >> period;
    
    for (int day = 1; day <= period; day++) {
        
        cout << "Enter patients for day " << day << ": ";
        cin >> patient;
        
        if (day % 3 == 0) {
            if (untreated > treated) {
                doctors++;
                cout << "--- A new doctor was hired! Total doctors: " << doctors << " ---" << endl;
            }
        }
        
        if (patient <= doctors) {
            treated += patient;
        } else {
            treated += doctors;
            untreated += (patient - doctors);
        }
        
        cout << "Day " << day << " Totals:" << endl;
        cout << "  Treated people = " << treated << endl;
        cout << "  Untreated people = " << untreated << endl;
        cout << "---------------------------------" << endl;
    }
    
    cout << "\n--- FINAL REPORT ---" << endl;
    cout << "Treated patients: " << treated << "." << endl;
    cout << "Untreated patients: " << untreated << "." << endl;

    return 0;
}

