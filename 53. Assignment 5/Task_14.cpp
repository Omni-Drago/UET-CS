#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int ORIGIN = 12;
const int DEST = 12;
const int PRODUCT = 5;
const int MODE = 3;
const int TARIFF = 5; 
const int MONTH = 12;

static long long tradeData[ORIGIN][DEST][PRODUCT][MODE][TARIFF][MONTH];

int main() {
    srand(time(0));
    cout << "Initializing 6D Array..." << endl;

    for (int o = 0; o < ORIGIN; o++)
        for (int d = 0; d < DEST; d++)
            for (int p = 0; p < PRODUCT; p++)
                for (int tr = 0; tr < MODE; tr++)
                    for (int ta = 0; ta < TARIFF; ta++)
                        for (int m = 0; m < MONTH; m++)
                            tradeData[o][d][p][tr][ta][m] = 30000 + (rand() % 90001);

    cout << "\n--- Origin Country vs Tariff Rate Trade Volume ---\n" << endl;

    cout << setw(10) << "Origin";
    for(int t=0; t<TARIFF; t++) {
        cout << setw(12) << "Slab " << (t+1) << " ";
    }
    cout << endl;
    cout << setw(10) << " "; 
    cout << setw(12) << "(0-20%)" << setw(13) << "(21-40%)" << setw(13) << "(41-60%)" << setw(13) << "(61-80%)" << setw(13) << "(81-100%)" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (int o = 0; o < ORIGIN; o++) {
        cout << setw(8) << "Country " << o;

        for (int ta = 0; ta < TARIFF; ta++) {
            long long slabTotal = 0;

            for (int d = 0; d < DEST; d++) {
                for (int p = 0; p < PRODUCT; p++) {
                    for (int tr = 0; tr < MODE; tr++) {
                        for (int m = 0; m < MONTH; m++) {
                            slabTotal += tradeData[o][d][p][tr][ta][m];
                        }
                    }
                }
            }
            cout << setw(13) << slabTotal;
        }
        cout << endl;
    }

    return 0;
}