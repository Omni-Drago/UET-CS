#include <iostream>
#include <fstream> 

using namespace std;

int main() {
    ofstream file("strips2.pgm");

    if (!file.is_open()) {
        cout << "Error: Could not create file." << endl;
        return 1;
    }

    file << "P2" << endl;
    file << "256 256" << endl;
    file << "15" << endl;

    for (int row = 0; row < 256; row++) {
        
        int pixelValue = row / 16; 

        
        for (int col = 0; col < 256; col++) {
            file << pixelValue << " ";
        }
        
        file << endl;
    }

    file.close();

    cout << "File 'strips2.pgm' generated successfully." << endl;
    return 0;
}