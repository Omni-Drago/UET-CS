#include <iostream>
#include <windows.h> // REQUIRED for: gotoxy, SetColor, Sleep (Console Control)
#include <fstream>   // REQUIRED for: File Handling (writing to score.txt)
#include <ctime>     // REQUIRED for: time(0) to seed random numbers
#include <conio.h>   // REQUIRED for: _getch() (Reading key press without Enter)

using namespace std;

// --- GLOBAL CONSTANTS ---
// These control the fundamental size of the game world. 
// Using constants makes the code safer and easier to modify later.
const int ROWS = 40; 
const int COLS = 60; 
const int ENEMY_COUNT = 12; // Total number of missiles patrolling the screen

// --- COLORS ---
// Mapping readable names to Windows Console integer codes for easier usage.
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define YELLOW 6
#define WHITE 7
#define GREY 8

// --- FUNCTION PROTOTYPES ---
// We declare these at the top so the 'main' function knows they exist.
// This allows us to organize the code by putting messy function logic at the bottom.
void ShowConsoleCursor(bool showFlag);
void SetColor(int color); 
void gotoxy(int x, int y);
void printStartScreen();  
void printMaze(char map[ROWS][COLS]);
void printPlayer(int x, int y);
void erasePlayer(int x, int y);
void movePlayer(int &pX, int &pY, char map[ROWS][COLS]); 
void printEnemy(int x, int y, bool right); 
void eraseEnemy(int x, int y, char map[ROWS][COLS]); 
void moveEnemies(int enemyX[], int enemyY[], bool enemyDir[], char map[ROWS][COLS]); 
void generateBullet(int pX, int pY, int &bX, int &bY, bool &isFired, int &ammo);
void moveBullet(int &bX, int &bY, bool &isFired, int enemyX[], int enemyY[], int &score, char map[ROWS][COLS]); 
void destroyRock(int bX, int bY, char map[ROWS][COLS]); 
void printGUI(); 
void updateScore(int score, int lives, int level, int ammo); 
void saveHighScore(int score);
void resetLevel(char map[ROWS][COLS], int level); 

// --- MAIN FUNCTION (Entry Point) ---
int main() {
    // 1. WINDOW SETUP
    // Forces the window to be 100 columns wide and 50 lines tall.
    // This prevents the map from "scattering" on small screens.
    system("mode con: cols=100 lines=50");

    // 2. RANDOMIZATION SEED
    // time(0) returns current time. Used as a seed so every game run is unique.
    srand(time(0)); 

    // 3. CONSOLE SETTINGS
    // Hides the blinking underscore cursor to prevent screen flickering/visual noise.
    ShowConsoleCursor(false); 

    bool isRunning = true; // Variable to keep the whole game application running
    bool firstRun = true;  // Variable to ensure Start Screen only shows on launch

    // --- OUTER LOOP: Handles Game Sessions (Replayability) ---
    while(isRunning) {
        
        // 4. MAP INITIALIZATION (2D Array)
        // Creating the grid in memory before drawing it.
        char map[ROWS][COLS];
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                // If we are at the edges (Row 0, Col 0, Last Row, Last Col)...
                if (i==0 || i==ROWS-1 || j==0 || j==COLS-1) 
                    map[i][j] = '#'; // ...Place a wall border
                else 
                    map[i][j] = ' '; // ...Otherwise place empty air
            }
        }

        // 5. GAME VARIABLES
        int pX = 28; // Player Start X (Horizontal Center)
        int pY = 36; // Player Start Y (Bottom of map)
        int lives = 3;
        int score = 0;
        int level = 1;
        int ammo = 5; 

        // 6. ENEMY SETUP (Parallel Arrays)
        // We use 3 arrays linked by index 'i'.
        // enemyX[0] belongs to the same enemy as enemyY[0] and enemyDir[0].
        int enemyX[ENEMY_COUNT] = { 5, 50, 15, 40, 10, 35, 20, 45, 8, 32, 4, 25 }; 
        int enemyY[ENEMY_COUNT] = { 4, 7, 10, 13, 16, 19, 22, 25, 5, 8, 11, 14 };  
        bool enemyDir[ENEMY_COUNT] = { true, false, true, false, true, false, true, false, true, false, true, false }; 
        
        // Bullet Variables
        int bX = -1; // -1 means bullet doesn't exist yet
        int bY = -1;
        bool isFired = false;
        
        // Enemy Speed Timer
        // Used to make enemies slower than the main game loop
        int enemyTimer = 0; 

        // Show Instructions (Only once per program run)
        if (firstRun) {
            printStartScreen();
            firstRun = false; 
        }

        // 7. INITIAL DRAW
        system("cls"); // Clear the screen completely
        resetLevel(map, level); // Generate rocks based on Level 1 density
        printMaze(map); // Draw walls and rocks
        printPlayer(pX, pY); // Draw player
        printGUI(); // Draw Scoreboard borders

        // --- INNER LOOP: Active Gameplay ---
        // Runs continuously as long as player is alive. 
        // Each loop iteration is one "Frame" of the game.
        while (lives > 0) {
            
            // A. Update Score Numbers (Fastest, every frame)
            updateScore(score, lives, level, ammo);

            // B. Player Movement
            // Checks keyboard input and updates pX/pY if valid
            movePlayer(pX, pY, map);

            // C. Shooting Input
            // GetAsyncKeyState checks if Space is held down without pausing the game
            if (GetAsyncKeyState(VK_SPACE) && !isFired) {
                if (ammo > 0) {
                    generateBullet(pX, pY, bX, bY, isFired, ammo);
                }
            }

            // D. Enemy Speed Control (The "Tick" System)
            int speedThreshold;
            
            // Determine how often enemies move based on Level
            if (level <= 3) speedThreshold = 3;      // Slow (Move every 4th frame)
            else if (level <= 6) speedThreshold = 2; // Medium (Move every 3rd frame)
            else speedThreshold = 1;                 // Fast (Move every 2nd frame)

            // Only update enemy position if enough "frames" have passed
            if (enemyTimer >= speedThreshold) {
                moveEnemies(enemyX, enemyY, enemyDir, map);
                enemyTimer = 0; // Reset counter
            }
            enemyTimer++; // Count this frame

            // E. Bullet Physics
            // Bullets always move fast (every frame)
            moveBullet(bX, bY, isFired, enemyX, enemyY, score, map); 

            // F. Collision Detection
            for(int i = 0; i < ENEMY_COUNT; i++) {
                // Check if Player is overlapping with any Enemy
                // abs() gets absolute distance. <3 X means horizontal overlap, <2 Y means vertical.
                if (abs(pX - enemyX[i]) < 3 && abs(pY - enemyY[i]) < 2) {
                    lives--;        
                    pX = 28; // Reset Player to start
                    pY = 36;
                    
                    // Visual Feedback: Flash Red
                    SetColor(RED);
                    printPlayer(pX, pY); 
                    Sleep(200); // Pause briefly to show hit
                    SetColor(WHITE);

                    // Full Redraw to fix any visual glitches
                    system("cls"); 
                    printMaze(map); 
                    printPlayer(pX, pY); 
                    printGUI();
                    Sleep(500); 
                }
            }

            // G. Level Up Condition
            // If player reaches top of screen (Y <= 2)
            if (pY <= 2) { 
                score += 100;
                level++;
                ammo = 5; // Reload
                pX = 28; 
                pY = 36; 
                
                // Regenerate map with higher difficulty
                resetLevel(map, level);
                
                system("cls");      
                printMaze(map); 
                printPlayer(pX, pY); 
                printGUI();
                Sleep(500); 
            }

            // Frame Rate Cap (20ms delay = approx 50 Frames Per Second)
            Sleep(20); 
        }

        // --- GAME OVER SEQUENCE ---
        system("cls");
        SetColor(RED);
        gotoxy(20, 15); cout << "===========================";
        gotoxy(20, 16); cout << "  G A M E   O V E R  ";
        gotoxy(20, 17); cout << "===========================";
        SetColor(WHITE);
        gotoxy(20, 19); cout << "Final Score: " << score;
        gotoxy(20, 20); cout << "Max Level: " << level;
        
        // Save score to file
        saveHighScore(score); 

        // Restart Menu
        SetColor(YELLOW);
        gotoxy(20, 23); cout << "Press 'R' to RESTART";
        gotoxy(20, 24); cout << "Press 'E' to EXIT";
        SetColor(WHITE);

        // Input loop: Wait until user presses R or E
        while(true) {
            char choice = _getch();
            if (choice == 'r' || choice == 'R') { 
                isRunning = true; // Keeps outer loop going
                break; 
            }
            else if (choice == 'e' || choice == 'E') { 
                isRunning = false; // Breaks outer loop -> Ends program
                break; 
            }
        }
    }
    return 0;
}

// --- FUNCTION DEFINITIONS ---

// Helper: Hides the flashing underscore cursor
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; 
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Helper: Changes text color
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Helper: Moves drawing cursor to X, Y
void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

// Intro Screen
void printStartScreen() {
    system("cls");
    SetColor(CYAN);
    cout << "\n\n";
    cout << "    #######################################" << endl;
    cout << "    #                                     #" << endl;
    cout << "    #      JET FIGHTER: ROCKY ROAD        #" << endl;
    cout << "    #                                     #" << endl;
    cout << "    #######################################" << endl;
    SetColor(YELLOW);
    cout << "\n    INSTRUCTIONS:" << endl;
    cout << "    1. ARROW KEYS to fly." << endl;
    cout << "    2. SPACE to fire missiles." << endl;
    cout << "    3. Avoid the RED MISSILES." << endl;
    cout << "    4. Blast ROCKS (1 hit destroys them)." << endl;
    SetColor(GREEN);
    cout << "\n    Press ANY KEY to launch..." << endl;
    _getch(); // Wait for user input
    SetColor(WHITE); 
}

// Prints the static elements (Walls and Rocks) based on the Map Array
void printMaze(char map[ROWS][COLS]) {
    gotoxy(0, 0); 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == '#') {
                SetColor(BLUE); cout << "#"; 
            } else if (map[i][j] != ' ') { 
                SetColor(YELLOW); cout << map[i][j]; // Rocks are Yellow
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    SetColor(WHITE); 
}

// Draws the Player Character
void printPlayer(int x, int y) {
    SetColor(CYAN);
    gotoxy(x, y);     cout << " ^ ";
    gotoxy(x, y + 1); cout << "=A=";
    SetColor(WHITE);
}

// Erases the Player Character (Prints spaces over old position)
void erasePlayer(int x, int y) {
    gotoxy(x, y);     cout << "   ";
    gotoxy(x, y + 1); cout << "   ";
}

// Logic: Handles Player Movement & Collision
void movePlayer(int &pX, int &pY, char map[ROWS][COLS]) {
    int targetX = pX;
    int targetY = pY;

    // Async Key State allows moving without pausing the game
    if (GetAsyncKeyState(VK_LEFT)) targetX -= 1;
    else if (GetAsyncKeyState(VK_RIGHT)) targetX += 1;
    else if (GetAsyncKeyState(VK_UP)) targetY -= 1;
    else if (GetAsyncKeyState(VK_DOWN)) targetY += 1;
    else return; // No key pressed, exit function

    // PREDICTIVE COLLISION: Check 4 corners of the jet against the map
    // If target position has a Rock or Wall, do NOT update pX/pY
    if (map[targetY][targetX] != ' ' || map[targetY][targetX+2] != ' ' || 
        map[targetY+1][targetX] != ' ' || map[targetY+1][targetX+2] != ' ') {
        return; 
    }

    // Move is valid: Erase old -> Update Coords -> Print New
    erasePlayer(pX, pY); 
    pX = targetX;        
    pY = targetY;
    printPlayer(pX, pY); 
}

// Draws Enemy based on direction
void printEnemy(int x, int y, bool right) {
    SetColor(RED);
    if (right) {
        gotoxy(x, y);     cout << "==>";
        gotoxy(x, y + 1); cout << "==>";
    } else {
        gotoxy(x, y);     cout << "<==";
        gotoxy(x, y + 1); cout << "<==";
    }
    SetColor(WHITE);
}

// Erases Enemy (Smart Erase)
// This checks the map array. If there was a Rock under the enemy, it redraws the Rock.
void eraseEnemy(int x, int y, char map[ROWS][COLS]) {
    for(int i=0; i<2; i++) {
        gotoxy(x, y + i);
        for(int j=0; j<3; j++) {
            if (map[y+i][x+j] != ' ') {
                SetColor(YELLOW);
                cout << map[y+i][x+j]; // Restore Rock
            } else {
                cout << " "; // Empty space
            }
        }
    }
    SetColor(WHITE);
}

// Logic: Moves all 12 enemies
void moveEnemies(int enemyX[], int enemyY[], bool enemyDir[], char map[ROWS][COLS]) {
    for (int i = 0; i < ENEMY_COUNT; i++) {
        eraseEnemy(enemyX[i], enemyY[i], map);
        
+        if (enemyDir[i]) { // Moving Right
            enemyX[i]++; 
            if (enemyX[i] >= (COLS - 4)) enemyX[i] = 2; // Wrap around right edge
        } else { // Moving Left
            enemyX[i]--; 
            if (enemyX[i] <= 1) enemyX[i] = (COLS - 5); // Wrap around left edge
        }
        
        printEnemy(enemyX[i], enemyY[i], enemyDir[i]);
    }
}

// Initializes a bullet
void generateBullet(int pX, int pY, int &bX, int &bY, bool &isFired, int &ammo) {
    bX = pX + 1; // Bullet starts at nose of jet
    bY = pY - 1;
    isFired = true;
    ammo--; // Decrease ammo count
    gotoxy(bX, bY); 
    SetColor(YELLOW); cout << "!"; 
    SetColor(WHITE);
}

// Advanced Helper: Finds and destroys a whole rock based on one hit point
void destroyRock(int bX, int bY, char map[ROWS][COLS]) {
    // Math to reverse-engineer rock position based on bullet hit
    // Rocks are spaced 3 rows apart (starting at 4) and 4 cols apart (starting at 3)
    int rockRow = 4 + ((bY - 4) / 3) * 3; 
    int rockCol = 3 + ((bX - 3) / 4) * 4;

    // Safety Check: Ensure coordinates are within bounds
    if (rockRow < 0 || rockRow >= ROWS || rockCol < 0 || rockCol >= COLS) return;

    // 1. Wipe Map Memory
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            map[rockRow + i][rockCol + j] = ' ';
        }
    }
    // 2. Wipe Visual Screen
    for(int i=0; i<2; i++) {
        gotoxy(rockCol, rockRow + i);
        cout << "   "; 
    }
}

// Logic: Moves bullet and checks collisions
void moveBullet(int &bX, int &bY, bool &isFired, int enemyX[], int enemyY[], int &score, char map[ROWS][COLS]) {
    if (isFired) {
        gotoxy(bX, bY); cout << " "; // Erase old bullet
        bY--; 
        
        if (bY <= 1) { isFired = false; return; } // Hit top wall

        // Collision: Bullet vs Rock
        if (map[bY][bX] != ' ') {
            destroyRock(bX, bY, map); // Destroy entire rock
            isFired = false;   
            score += 5;        
            return;
        }

        // Collision: Bullet vs Enemy
        for(int i=0; i < ENEMY_COUNT; i++) {
            // Hitbox Check
            if (bX >= enemyX[i] && bX <= enemyX[i]+2 && bY >= enemyY[i] && bY <= enemyY[i]+1) {
                score += 20; 
                eraseEnemy(enemyX[i], enemyY[i], map); 
                enemyX[i] = 2; // Reset enemy
                isFired = false;
                return;
            }
        }
        
        // If nothing hit, redraw bullet
        if (isFired) { 
            gotoxy(bX, bY); 
            SetColor(YELLOW); cout << "!"; 
            SetColor(WHITE);
        }
    }
}

// Draws static UI labels (Score, Lives...)
void printGUI() {
    SetColor(WHITE);
    gotoxy(65, 5); cout << "---------------";
    gotoxy(65, 6); cout << " SCORE : ";
    gotoxy(65, 7); cout << " LIVES : ";
    gotoxy(65, 8); cout << " LEVEL : ";
    gotoxy(65, 9); cout << " AMMO  : ";
    gotoxy(65, 10); cout << "---------------";
}

// Updates UI Numbers
void updateScore(int score, int lives, int level, int ammo) {
    SetColor(WHITE);
    gotoxy(74, 6); cout << score << "   ";
    gotoxy(74, 7); cout << lives << "   ";
    gotoxy(74, 8); cout << level << "   ";
    gotoxy(74, 9); cout << ammo << "   "; 
}

// Appends high score to a text file
void saveHighScore(int score) {
    fstream file;
    file.open("score.txt", ios::out | ios::app); // "app" means append mode
    if (file.is_open()) {
        file << "Score: " << score << endl;
        file.close();
    }
}

// Generates Rocks based on Difficulty
void resetLevel(char map[ROWS][COLS], int level) {
    // 1. Clear Inner Map
    for(int i=1; i<ROWS-1; i++) {
        for(int j=1; j<COLS-1; j++) {
            map[i][j] = ' ';
        }
    }

    // 2. Increase Density (+3% per level, Cap at 25%)
    int density = 6 + (level * 3);
    if (density > 25) density = 25;

    // 3. Loop through grid and place rocks
    for (int i = 4; i < (ROWS - 6); i+=3) { 
        for (int j = 3; j < (COLS - 5); j+=4) { 
            // Random chance to place a rock
            if ((rand() % 100) < density) { 
                // Write Rock shape into Map Array
                map[i][j]   = '/'; map[i][j+1]   = '-'; map[i][j+2]   = '\\';
                map[i+1][j] = '\\'; map[i+1][j+1] = '_'; map[i+1][j+2] = '/';
            }
        }
    }
}