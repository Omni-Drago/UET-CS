#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("pattern3.pgm");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "P2" << endl;
    file << "256 256" << endl;
    file << "255" << endl;

    int squareSize = 32; 

    for (int row = 0; row < 256; row++) {
        
        for (int col = 0; col < 256; col++) {
            
            int blockRow = row / squareSize;
            int blockCol = col / squareSize;

            if ((blockRow + blockCol) % 2 == 0) {
                file << "255 ";
            } else {
                file << "0 ";
            }
        }
        
        file << endl;
    }

    file.close();
    
    cout << "File 'pattern3.pgm' generated successfully." << endl;

    return 0;
}