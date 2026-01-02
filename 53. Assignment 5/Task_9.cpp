#include <iostream>
#include <fstream> 

using namespace std;

int main() {
    ofstream file("pattern4.ppm");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "P3" << endl;
    file << "256 256" << endl;
    file << "255" << endl;

    int squareSize = 16; 

    for (int row = 0; row < 256; row++) {
        
        for (int col = 0; col < 256; col++) {
            
            int blockRow = row / squareSize;
            int blockCol = col / squareSize;
            
            int colorValue;

            if ((blockRow + blockCol) % 2 == 0) {
                colorValue = 255;
            } else {
                colorValue = 0;  
            }

            file << colorValue << " " << colorValue << " " << colorValue << " ";
        }
        
        file << endl;
    }

    file.close();
    
    cout << "File 'pattern4.ppm' generated successfully." << endl;

    return 0;
}