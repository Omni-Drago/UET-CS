#include <iostream>
#include <fstream>   
#include <string>    
#include <windows.h>
#include <limits>    // Used for input validation logic (clearing the buffer).  
#include <cctype>    // Required for isdigit() and ispunct(). ispunct function in C++ is a character classification function that checks if a given character is a punctuation character as defined by the current C locale.
#include <cstdio>    // Required for remove() and rename()

using namespace std;

// --- 1. DATA STRUCTURES --- (Custom Data Type)
struct Game {
    string title;
    string platform;
    string genre;
    float price;
    int stock;
};

// Constants
const int MAX_GAMES = 100;

// --- 2. FUNCTION PROTOTYPES ---

// File & Data Management
void loadData(Game inventory[], int &count); //tell the compiler what functions are available before they are actually defined. This allows main() to call functions that are written at the bottom of the file.
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

// Authentication & System
void initializeSystem(); // Checks for first run
void signupUser(int role);
void deleteUser();       // Remove Admin/Employee
bool loginUser(int role);

// Helpers & Validation
bool checkDuplicate(string filename, string input, int type);
bool isValidEmail(string email);     
bool isValidPassword(string password); 
int getValidInt(); 
float getValidFloat(); 
void waitForInput();
void setConsoleColor(); 


// --- 3. MAIN FUNCTION ---
int main() {
    Game inventory[MAX_GAMES]; 
    int gameCount = 0;

    setConsoleColor(); 
    
    // 1. First Run Check
    initializeSystem(); //Checks if an admin exists immediately. If not, it forces a setup.

    // 2. Load Data
    loadData(inventory, gameCount);

    int choice;
    do {
        system("cls");
        cout << "=======================================" << endl;
        cout << "   VIDEO GAME STORE MANAGEMENT SYSTEM  " << endl;
        cout << "=======================================" << endl;
        cout << "1. Login as Admin" << endl;
        cout << "2. Login as Employee" << endl;
        cout << "3. Exit" << endl;
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
            case 3:
                saveData(inventory, gameCount);
                cout << "Exiting system... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                waitForInput();
        }
    } while (choice != 3);

    return 0;
}

// --- 4. SYSTEM & AUTH FUNCTIONS ---

void initializeSystem() {
    fstream file;
    file.open("admins.csv", ios::in);
    
    // Check if file is empty or missing
    bool isEmpty = true;
    if (file.is_open()) {
        if (file.peek() != ifstream::traits_type::eof()) { //This is a special constant value that represents the End of File (EOF).traits_type: A set of rules for handling characters.
            isEmpty = false;
        }
        file.close();
    }

    if (isEmpty) {
        system("cls");
        cout << "!!! FIRST RUN DETECTED !!!" << endl;
        cout << "No Admin account found." << endl;
        cout << "Please create the OWNER account to start." << endl;
        cout << "---------------------------------------" << endl;
        signupUser(1); // Force create Admin
        waitForInput();
    }
}

void signupUser(int role) {
    string user, email, pass;
    string filename = (role == 1) ? "admins.csv" : "employees.csv"; //It is asking the computer: "Is the value inside the variable role equal to 1?"

    // Username Loop
    while (true) {
        cout << "Enter Username: "; 
        cin >> user;
        if (checkDuplicate(filename, user, 0)) {
            cout << "Error: Username already exists! Please choose another.\n";
        } else {
            break;
        }
    }
    
    // Email Loop
    while(true) {
        cout << "Enter Email (must have @ and .): ";
        cin >> email;
        if(!isValidEmail(email)) {
            cout << "Invalid Email Format! Try again.\n";
        } 
        else if (checkDuplicate(filename, email, 1)) {
            cout << "Error: Email already registered! Use another.\n";
        } 
        else {
            break;
        }
    }

    // Password Loop
    while(true) {
        cout << "Enter Password (must have number & special char): ";
        cin >> pass;
        if(isValidPassword(pass)) break;
        else cout << "Weak Password! Try again.\n";
    }

    fstream file;
    file.open(filename.c_str(), ios::out | ios::app);
    if(file.is_open()) {
        file << user << "," << email << "," << pass << endl; 
        file.close();
        cout << "Registered Successfully!\n";
    }
}

bool loginUser(int role) {
    string iUser, iPass;
    string fUser, fEmail, fPass; 
    bool userFound = false;
    string correctPass = "";

    cout << "Username: "; cin >> iUser;
    
    fstream file;
    string filename = (role == 1) ? "admins.csv" : "employees.csv"; ////It is asking the computer: "Is the value inside the variable role equal to 1?"
    file.open(filename.c_str(), ios::in);
    
    if(file.is_open()) {
        while(getline(file, fUser, ',') && getline(file, fEmail, ',') && getline(file, fPass)) {
            if(fUser == iUser) {
                userFound = true;
                correctPass = fPass;
                break; 
            }
        }
        file.close();
    }

    if (!userFound) {
        cout << "Error: Username not found." << endl;
        return false;
    }

    cout << "Password: "; cin >> iPass;

    if (iPass == correctPass) {
        return true;
    } else {
        cout << "Error: Incorrect Password!" << endl;
        return false;
    }
}

void deleteUser() {
    int type;
    string targetUser;
    
    cout << "\n--- DELETE USER ---" << endl;
    cout << "1. Delete an Admin" << endl;
    cout << "2. Delete an Employee" << endl;
    cout << "Enter choice: ";
    type = getValidInt();

    if (type != 1 && type != 2) {
        cout << "Invalid choice." << endl;
        return;
    }

    string filename = (type == 1) ? "admins.csv" : "employees.csv";
    string tempFilename = "temp.csv";

    cout << "Enter Username to DELETE: ";
    cin >> targetUser;

    if (!checkDuplicate(filename, targetUser, 0)) {
        cout << "Error: User not found!" << endl;
        return;
    }

    fstream original, temp;
    original.open(filename.c_str(), ios::in); //converts your modern C++ text variable into an old-school format that the file system understands.
    temp.open(tempFilename.c_str(), ios::out);

    string fUser, fEmail, fPass;
    bool deleted = false;

    while (getline(original, fUser, ',') && getline(original, fEmail, ',') && getline(original, fPass)) {
        if (fUser == targetUser) {
            deleted = true; 
            cout << "User '" << targetUser << "' deleted." << endl;
        } else {
            temp << fUser << "," << fEmail << "," << fPass << endl; 
        }
    }

    original.close();
    temp.close();

    remove(filename.c_str());
    rename(tempFilename.c_str(), filename.c_str());
}

// --- 5. ADMIN MENUS & FUNCTIONS ---

void adminMenu(Game inventory[], int &count) {
    int choice;
    do {
        system("cls");
        cout << "--- ADMIN DASHBOARD ---" << endl;
        cout << "1. Add New Game" << endl;
        cout << "2. Delete Game" << endl;
        cout << "3. Search for a Game" << endl;
        cout << "4. View All Games (Inventory)" << endl;
        cout << "5. Register New User" << endl; 
        cout << "6. Delete User" << endl;       
        cout << "7. Logout" << endl;
        cout << "Enter choice: ";
        choice = getValidInt();

        switch (choice) {
            case 1: addGame(inventory, count); break;
            case 2: deleteGame(inventory, count); break;
            case 3: searchGame(inventory, count); break;
            case 4: viewInventory(inventory, count); break;
            case 5: {
                cout << "\n1. Register Admin\n2. Register Employee\nChoice: ";
                int regChoice = getValidInt();
                if(regChoice == 1 || regChoice == 2) signupUser(regChoice);
                else cout << "Invalid choice.\n";
                break;
            }
            case 6: deleteUser(); break;
            case 7: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
        if (choice != 7) waitForInput();
    } while (choice != 7);
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

// --- 6. EMPLOYEE MENUS & FUNCTIONS ---

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

// --- 7. UTILITY, SEARCH, SORT ---

void searchGame(const Game inventory[], int count) {
    string t; cout << "Enter Title to Search: "; cin >> t;
    bool found = false;
    for(int i=0; i<count; i++) {
        if(inventory[i].title == t) {
            cout << "\n--- GAME FOUND ---" << endl;
            cout << "Title:    " << inventory[i].title << endl;
            cout << "Genre:    " << inventory[i].genre << endl; 
            cout << "Platform: " << inventory[i].platform << endl;
            cout << "Price:    $" << inventory[i].price << endl;
            cout << "Stock:    " << inventory[i].stock << endl; 
            found = true;
            return;
        }
    }
    cout << "Game not found in inventory.\n";
}

void viewInventory(const Game inventory[], int count) {
    cout << "\nTitle\tPlatform\tPrice\tStock" << endl;
    for(int i=0; i<count; i++)
        cout << inventory[i].title << "\t" << inventory[i].platform << "\t\t" << inventory[i].price << "\t" << inventory[i].stock << endl;
}

void viewByPrice(const Game inventory[], int count) {
    Game temp[MAX_GAMES];
    for(int i=0; i<count; i++) temp[i] = inventory[i];
    
    for(int i=0; i<count-1; i++) {
        for(int j=0; j<count-i-1; j++) {
            if(temp[j].price > temp[j+1].price) {
                Game t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }
        }
    }
    viewInventory(temp, count);
}

// --- 8. FILE I/O ---

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
            
            file.ignore(numeric_limits<streamsize>::max(), '\n'); //It tells the computer: "Skip everything else on the current line and move the cursor to the start of the next line."
        }
        file.close();
    } else {
        count = 0;
    }
}

// --- 9. HELPERS ---

bool checkDuplicate(string filename, string input, int type) {
    fstream file;
    file.open(filename.c_str(), ios::in);
    if (!file.is_open()) return false; 

    string fUser, fEmail, fPass;
    while (getline(file, fUser, ',') && getline(file, fEmail, ',') && getline(file, fPass)) {
        if (type == 0 && fUser == input) { file.close(); return true; }
        if (type == 1 && fEmail == input) { file.close(); return true; }
    }
    file.close();
    return false;
}

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return x;
}

float getValidFloat() {
    float x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return x;
}

void setConsoleColor() {
    system("color 1F"); 
}

void waitForInput() {
    cout << endl; 
    system("pause"); 
}