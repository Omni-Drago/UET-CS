#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input.pgm");

    ofstream outFile("inverted.pgm");

    if (!inFile.is_open()) {
        cout << "Error: Could not open 'input.pgm'." << endl;
        cout << "Please check if the file exists and is named correctly." << endl;
        return 1;
    }

    string format;
    int width, height, maxVal;

    inFile >> format >> width >> height >> maxVal;

    outFile << format << endl;
    outFile << width << " " << height << endl;
    outFile << maxVal << endl;

    cout << "Processing image of size " << width << "x" << height << "..." << endl;

    int pixel;
    
    while (inFile >> pixel) {
        
        int invertedPixel = maxVal - pixel;

        outFile << invertedPixel << " ";
    }

    inFile.close();
    outFile.close();

    cout << "Success! Created 'inverted.pgm'." << endl;
    cout << "Open the new file in IrfanView to see the negative image." << endl;

    return 0;
}