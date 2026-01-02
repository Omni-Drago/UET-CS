#include <iostream>
#include <fstream>   
#include <string>    
#include <windows.h>
#include <limits>    
#include <cctype>   // Required for isdigit() and ispunct()

using namespace std;

// --- 1. DATA STRUCTURES ---
struct Game {
    string title;
    string platform;
    string genre;
    float price;
    int stock;
};

// --- 2. FUNCTION PROTOTYPES ---

// File & Data Management
void loadData(Game inventory[], int &count);
void saveData(const Game inventory[], int count);

// Menus
void adminMenu(Game inventory[], int &count);
void employeeMenu(Game inventory[], int &count);

// Admin Functions
void addGame(Game inventory[], int &count);
void deleteGame(Game inventory[], int &count);
void searchGame(const Game inventory[], int count);
void viewInventory(const Game inventory[], int count);

// Employee Functions
void sellGame(Game inventory[], int count);
void processTradeIn(Game inventory[], int count);  
void viewByPrice(const Game inventory[], int count);

// Authentication & Helpers
void signupUser(int role);
bool loginUser(int role);
bool isValidEmail(string email);     
bool isValidPassword(string password); 
int getValidInt(); 
float getValidFloat(); 
void waitForInput();
void setConsoleColor(); 

// Constants
const int MAX_GAMES = 100;

// --- 3. MAIN FUNCTION ---
int main() {
    Game inventory[MAX_GAMES]; 
    int gameCount = 0;

    setConsoleColor(); 
    loadData(inventory, gameCount);

    int choice;
    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "   VIDEO GAME STORE MANAGEMENT SYSTEM  " << endl;
        cout << "=======================================" << endl;
        cout << "1. Login as Admin" << endl;
        cout << "2. Login as Employee" << endl;
        cout << "3. Register New User (Signup)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getValidInt(); 

        switch (choice) {
            case 1:
                if (loginUser(1)) {
                    adminMenu(inventory, gameCount); 
                } else {
                    cout << "Login Failed!" << endl;
                    waitForInput();
                }
                break;
            case 2:
                if (loginUser(2)) {
                    employeeMenu(inventory, gameCount); 
                } else {
                    cout << "Login Failed!" << endl;
                    waitForInput();
                }
                break;
            case 3: {
                cout << "\n1. Register Admin\n2. Register Employee\nChoice: ";
                int regChoice = getValidInt();
                if(regChoice == 1 || regChoice == 2) signupUser(regChoice);
                else cout << "Invalid choice.\n";
                waitForInput();
                break;
            }
            case 4:
                saveData(inventory, gameCount);
                cout << "Exiting system... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                waitForInput();
        }
    } while (choice != 4);

    return 0;
}

// --- 4. ADMIN FUNCTIONS ---
void adminMenu(Game inventory[], int &count) {
    int choice;
    do {
        system("cls");
        cout << "--- ADMIN DASHBOARD ---" << endl;
        cout << "1. Add New Game" << endl;
        cout << "2. Delete Game" << endl;
        cout << "3. Search for a Game" << endl;
        cout << "4. View All Games (Inventory)" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter choice: ";
        choice = getValidInt();

        switch (choice) {
            case 1: addGame(inventory, count); break;
            case 2: deleteGame(inventory, count); break;
            case 3: searchGame(inventory, count); break;
            case 4: viewInventory(inventory, count); break;
            case 5: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
        if (choice != 5) waitForInput();
    } while (choice != 5);
}

void addGame(Game inventory[], int &count) {
    if (count >= MAX_GAMES) {
        cout << "Inventory Full!" << endl;
        return;
    }
    cout << "\n--- ADD NEW GAME ---" << endl;
    cout << "Enter Title (No Spaces): "; cin >> inventory[count].title;
    cout << "Enter Platform: "; cin >> inventory[count].platform;
    cout << "Enter Genre: "; cin >> inventory[count].genre;
    
    cout << "Enter Price ($): "; 
    inventory[count].price = getValidFloat(); 
    
    cout << "Enter Stock: "; 
    inventory[count].stock = getValidInt(); 

    count++;
    cout << "Game Added Successfully!" << endl;
}

void deleteGame(Game inventory[], int &count) {
    string searchTitle;
    cout << "Enter Game Title to Delete: "; cin >> searchTitle;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (inventory[i].title == searchTitle) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            found = true;
            cout << "Game Deleted!" << endl;
            break;
        }
    }
    if (!found) cout << "Game not found." << endl;
}

// --- 5. EMPLOYEE FUNCTIONS ---
void employeeMenu(Game inventory[], int &count) {
    int choice;
    do {
        system("cls");
        cout << "--- EMPLOYEE DASHBOARD ---" << endl;
        cout << "1. Sell a Game" << endl;
        cout << "2. Process Trade-In" << endl; 
        cout << "3. Search for a Game" << endl;
        cout << "4. View All Games (By Price)" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter choice: ";
        choice = getValidInt();

        switch (choice) {
            case 1: sellGame(inventory, count); break;
            case 2: processTradeIn(inventory, count); break;
            case 3: searchGame(inventory, count); break;
            case 4: viewByPrice(inventory, count); break;
            case 5: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
        if (choice != 5) waitForInput();
    } while (choice != 5);
}

void sellGame(Game inventory[], int count) {
    string searchTitle;
    cout << "\n--- SELL A GAME ---" << endl;
    cout << "Enter Game Title: "; cin >> searchTitle;
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (inventory[i].title == searchTitle) {
            cout << "Stock: " << inventory[i].stock << " | Price: $" << inventory[i].price << endl;
            if (inventory[i].stock > 0) {
                cout << "Enter Qty to Sell: "; 
                int qty = getValidInt();
                if (qty <= inventory[i].stock) {
                    inventory[i].stock -= qty;
                    cout << "Total: $" << (qty * inventory[i].price) << endl;
                } else cout << "Not enough stock!" << endl;
            } else cout << "Out of Stock!" << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Game not found." << endl;
}

void processTradeIn(Game inventory[], int count) {
    string searchTitle;
    cout << "\n--- PROCESS TRADE-IN ---" << endl;
    cout << "Enter Game Title: "; cin >> searchTitle;
    bool found = false;
    for(int i=0; i<count; i++) {
        if(inventory[i].title == searchTitle) {
            cout << "Current Stock: " << inventory[i].stock << endl;
            cout << "Enter Quantity to Add: ";
            int qty = getValidInt();
            inventory[i].stock += qty;
            cout << "Stock Updated Successfully!" << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "Game not in system. Admin must add it first." << endl;
}

// --- 6. UTILITY, VALIDATION & FILE I/O ---


bool isValidEmail(string email) {
    bool hasAt = false;
    bool hasDot = false;

    for (int i = 0; i < (int)email.length(); i++) {
        if (email[i] == '@') hasAt = true;
        if (email[i] == '.') hasDot = true;
    }
    return hasAt && hasDot;
}

bool isValidPassword(string password) {
    bool hasDigit = false;
    bool hasSpecial = false;

    for (int i = 0; i < (int)password.length(); i++) {
        if (isdigit(password[i])) hasDigit = true; 
        if (ispunct(password[i])) hasSpecial = true; 
    }
    return hasDigit && hasSpecial;
}

int getValidInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return x;
}

float getValidFloat() {
    float x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return x;
}

// CSV File Handling 
void saveData(const Game inventory[], int count) {
    fstream file;
    file.open("games.csv", ios::out); 
    if (file.is_open()) {
        file << count << endl;
        for (int i = 0; i < count; i++) {
            file << inventory[i].title << "," 
                 << inventory[i].platform << "," 
                 << inventory[i].genre << "," 
                 << inventory[i].price << "," 
                 << inventory[i].stock << endl;
        }
        file.close();
    }
}

void loadData(Game inventory[], int &count) {
    fstream file;
    file.open("games.csv", ios::in);
    
    if (file.is_open()) {
        file >> count;
        file.ignore();
        
        for (int i = 0; i < count; i++) {
            getline(file, inventory[i].title, ',');
            getline(file, inventory[i].platform, ',');
            getline(file, inventory[i].genre, ',');
            
            char comma;
            file >> inventory[i].price >> comma >> inventory[i].stock;
            
            file.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        file.close();
    } else {
        count = 0;
    }
}

// --- AUTH FUNCTIONS ---

void signupUser(int role) {
    string user, email, pass;
    cout << "Enter Username: "; 
    cin >> user;
    
    // Email Validation Loop
    while(true) {
        cout << "Enter Email (must have @ and .): ";
        cin >> email;
        if(isValidEmail(email)) break;
        else cout << "Invalid Email! Try again.\n";
    }

    // Password Validation Loop
    while(true) {
        cout << "Enter Password (must have number & special char): ";
        cin >> pass;
        if(isValidPassword(pass)) break;
        else cout << "Weak Password! Try again.\n";
    }

    fstream file;
    string filename = (role == 1) ? "admins.csv" : "employees.csv";
    file.open(filename.c_str(), ios::out | ios::app);
    if(file.is_open()) {
        // Save as CSV: User,Email,Pass
        file << user << "," << email << "," << pass << endl; 
        file.close();
        cout << "Registered Successfully!\n";
    }
}

bool loginUser(int role) {
    string iUser, iPass;
    string fUser, fEmail, fPass; 
    
    cout << "User: "; cin >> iUser;
    cout << "Pass: "; cin >> iPass;
    
    fstream file;
    string filename = (role == 1) ? "admins.csv" : "employees.csv";
    file.open(filename.c_str(), ios::in);
    
    if(file.is_open()) {

        while(getline(file, fUser, ',') && getline(file, fEmail, ',') && getline(file, fPass)) {
            
            if(fUser == iUser && fPass == iPass) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void viewInventory(const Game inventory[], int count) {
    cout << "\nTitle\tPlatform\tPrice\tStock" << endl;
    for(int i=0; i<count; i++)
        cout << inventory[i].title << "\t" << inventory[i].platform << "\t\t" << inventory[i].price << "\t" << inventory[i].stock << endl;
}

void viewByPrice(const Game inventory[], int count) {
    Game temp[MAX_GAMES];
    for(int i=0; i<count; i++) temp[i] = inventory[i];
    // Bubble Sort
    for(int i=0; i<count-1; i++) {
        for(int j=0; j<count-i-1; j++) {
            if(temp[j].price > temp[j+1].price) {
                Game t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }
        }
    }
    viewInventory(temp, count);
}

void searchGame(const Game inventory[], int count) {
    string t; cout << "Title: "; cin >> t;
    for(int i=0; i<count; i++) {
        if(inventory[i].title == t) {
            cout << "Found: " << inventory[i].title << " $" << inventory[i].price << endl;
            return;
        }
    }
    cout << "Not found.\n";
}

void setConsoleColor() {
    system("color 1F"); 
}

void waitForInput() {
    cout << endl; 
    system("pause"); 
}