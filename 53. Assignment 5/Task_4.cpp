#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream file("strips3.pgm");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "P2" << endl;
    file << "256 256" << endl;
    file << "255" << endl;

    for (int row = 0; row < 256; row++) {
        
        for (int col = 0; col < 256; col++) {
            
            file << row << " ";
        }
        
        file << endl;
    }

    file.close();
    
    cout << "File 'strips3.pgm' generated successfully." << endl;
    return 0;
}