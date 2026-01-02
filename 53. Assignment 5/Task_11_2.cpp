#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    
    srand(time(0));

    
    const int ORIGIN_COUNTRIES = 12;
    const int DEST_COUNTRIES = 12;
    const int PRODUCTS = 5;   
    const int MODES = 3;      
    const int TARIFFS = 5;    
    const int MONTHS = 12;

    static long long tradeData[ORIGIN_COUNTRIES][DEST_COUNTRIES][PRODUCTS][MODES][TARIFFS][MONTHS];

    cout << "Initializing 6D Array with random trade data (30k - 120k)..." << endl;

    for (int o = 0; o < ORIGIN_COUNTRIES; o++) {
        for (int d = 0; d < DEST_COUNTRIES; d++) {
            for (int p = 0; p < PRODUCTS; p++) {
                for (int tr = 0; tr < MODES; tr++) {
                    for (int ta = 0; ta < TARIFFS; ta++) {
                        for (int m = 0; m < MONTHS; m++) {
                            
                            long long value = 30000 + (rand() % 90001);
                            
                            tradeData[o][d][p][tr][ta][m] = value;
                        }
                    }
                }
            }
        }
    }

    cout << "Array initialized successfully." << endl;
    
    cout << "Sample Data (Country 0 to Country 1, Product 0, Sea, Tariff 0, Jan): " 
         << tradeData[0][1][0][0][0][0] << endl;

    return 0;
}