#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> parseCSVLine(string line) {
    vector<string> result;
    string cell = "";
    bool insideQuotes = false;

    for (char c : line) {
        if (c == '"') {
            insideQuotes = !insideQuotes; 
        } else if (c == ',' && !insideQuotes) {
            result.push_back(cell); 
            cell = "";
        } else {
            cell += c;
        }
    }
    result.push_back(cell); 
    return result;
}

int main() {
    ifstream file("countries of the world.csv");

    if (!file.is_open()) {
        cout << "Error: Could not open 'countries of the world.csv'" << endl;
        return 1;
    }

    string line;
    getline(file, line); 
    
    cout << left << setw(20) << "Country" 
         << setw(20) << "Region" 
         << setw(15) << "Population" 
         << setw(15) << "Area" 
         << setw(10) << "GDP" 
         << setw(10) << "Literacy" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    int rows = 0;
    while (getline(file, line) && rows < 20) { 
        vector<string> row = parseCSVLine(line);

        if (row.size() > 9) {
            string country = row[0];
            string region = row[1];
            string pop = row[2];
            string area = row[3];
            string gdp = row[8];
            string lit = row[9];

            cout << left << setw(20) << country.substr(0, 18) 
                 << setw(20) << region.substr(0, 18) 
                 << setw(15) << pop 
                 << setw(15) << area 
                 << setw(10) << gdp 
                 << setw(10) << lit << endl;
            rows++;
        }
    }

    file.close();
    return 0;
}