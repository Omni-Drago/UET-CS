#include <iostream>
#include <fstream> // Required for file handling [cite: 1844]

using namespace std;

int main() {
    ofstream file("strips1.pgm");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "P2" << endl;
    file << "256 256" << endl;
    file << "3" << endl;

    for (int row = 0; row < 256; row++) {
        
        for (int col = 0; col < 256; col++) {
            
            
            if (row < 64) {
                file << "2 ";
            } 
            else if (row < 128) {
                file << "0 ";
            } 
            else if (row < 192) {
                file << "3 ";
            } 
            else {
                file << "1 ";
            }
        }
        
        file << endl;
    }

    file.close();
    
    cout << "File 'strips1.pgm' generated successfully." << endl;
    
    return 0;
}