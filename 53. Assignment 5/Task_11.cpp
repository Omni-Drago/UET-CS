#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ifstream inFile("input.ppm");
    ofstream outFile("inverted.ppm");

    if (!inFile.is_open()) {
        cout << "Error: Could not open 'input.ppm'." << endl;
        return 1;
    }

    string format;
    int width, height, maxVal;

    inFile >> format >> width >> height >> maxVal;

    if (format != "P3") {
        cout << "Error: Input file is not a P3 PPM file." << endl;
        return 1;
    }

    outFile << format << endl;
    outFile << width << " " << height << endl;
    outFile << maxVal << endl;

    cout << "Processing PPM image..." << endl;

    int r, g, b;
    
    while (inFile >> r >> g >> b) {
        int newR = maxVal - r;
        int newG = maxVal - g;
        int newB = maxVal - b;

        outFile << newR << " " << newG << " " << newB << " ";
    }

    inFile.close();
    outFile.close();

    cout << "Success! Created 'inverted.ppm'." << endl;
    return 0;
}