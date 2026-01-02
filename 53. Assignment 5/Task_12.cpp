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

    for (int o = 0; o < ORIGIN; o++) {
        for (int d = 0; d < DEST; d++) {
            for (int p = 0; p < PRODUCT; p++) {
                for (int tr = 0; tr < MODE; tr++) {
                    for (int ta = 0; ta < TARIFF; ta++) {
                        for (int m = 0; m < MONTH; m++) {
                            tradeData[o][d][p][tr][ta][m] = 30000 + (rand() % 90001);
                        }
                    }
                }
            }
        }
    }

    cout << "\n--- Country-to-Country Total Trade Matrix ---\n" << endl;

    cout << "      ";
    for (int i = 0; i < 12; i++) {
        cout << setw(10) << "C" << i;
    }
    cout << endl << endl;

    for (int i = 0; i < ORIGIN; i++) {
        
        cout << "C" << i << "   ";

        for (int j = 0; j < DEST; j++) {
            
            if (i == j) {
                cout << setw(11) << " ";
            } 
            else {
                long long totalTrade = 0;

                for (int p = 0; p < PRODUCT; p++) {
                    for (int tr = 0; tr < MODE; tr++) {
                        for (int ta = 0; ta < TARIFF; ta++) {
                            for (int m = 0; m < MONTH; m++) {
                                totalTrade += tradeData[i][j][p][tr][ta][m];
                            }
                        }
                    }
                }
                
                cout << setw(11) << totalTrade;
            }
        }
        cout << endl;
    }

    return 0;
}