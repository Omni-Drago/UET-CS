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
    cout << "Initializing 6D Array... (This may take a second)" << endl;

    for (int o = 0; o < ORIGIN; o++)
        for (int d = 0; d < DEST; d++)
            for (int p = 0; p < PRODUCT; p++)
                for (int tr = 0; tr < MODE; tr++)
                    for (int ta = 0; ta < TARIFF; ta++)
                        for (int m = 0; m < MONTH; m++)
                            tradeData[o][d][p][tr][ta][m] = 30000 + (rand() % 90001);

    cout << "\n--- Month-wise Average Trade Analysis ---\n" << endl;
    cout << left << setw(15) << "Month" << setw(20) << "Total Trade" << setw(20) << "Average Trade" << endl;
    cout << "-------------------------------------------------------" << endl;

    for (int m = 0; m < MONTH; m++) {
        long long monthTotal = 0;
        long long count = 0;

        for (int o = 0; o < ORIGIN; o++) {
            for (int d = 0; d < DEST; d++) {
                for (int p = 0; p < PRODUCT; p++) {
                    for (int tr = 0; tr < MODE; tr++) {
                        for (int ta = 0; ta < TARIFF; ta++) {
                            monthTotal += tradeData[o][d][p][tr][ta][m];
                            count++; 
                        }
                    }
                }
            }
        }

        double average = (double)monthTotal / count;

        cout << "Month " << setw(8) << (m + 1) 
             << setw(20) << monthTotal 
             << setw(20) << fixed << setprecision(2) << average << endl;
    }

    return 0;
}