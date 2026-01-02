#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("strips4.pgm");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "P2" << endl;
    file << "256 256" << endl;
    file << "15" << endl; 

    for (int row = 0; row < 256; row++) {
        
        for (int col = 0; col < 256; col++) {
            
            int pixelValue = col / 16; 
            
            file << pixelValue << " ";
        }
        
        file << endl;
    }

    file.close();
    
    cout << "File 'strips4.pgm' generated successfully." << endl;

    return 0;
}