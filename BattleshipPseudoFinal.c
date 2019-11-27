/*
enum Marks{Hit, Miss, Water, Ship};

enum ShipType{Pat, Sub, Dest, Battle, Carrier};

// Makes a board of randomly generated values where ships are placed
// Pre: none
// Post: randomly puts ships on grid
void PlaceShips(char emptyGrid[ROWS][COLUMNS]);

// Creates a play grid based on the ship placements from PlaceShips
// Pre: A grid with ships was created
// Post: A grid consisting of ships and blank spaces is created but not displayed
void InitGrid();

// Prints the grid using only water, hit and miss marks
// Pre: A play grid has been created
// post: An updated grid is printed to the screen
void PrintGrid(char grid[ROWS][COLUMNS]);

// Tests if they hit or missed the ship
// Pre: A valid input combination is entered
// Post: Tells user if they hit or missed the ship
void HitMiss(char player[ROWS][COLUMNS], char boardHidden[ROWS][COLUMNS], int, int);

main(){
    int attempts;   // Number of guess attempts
    int maxAttempts;    // Maximum number of guess attempts
    int shipCount;      // Number of remaining ships on board

    const int ROWS    = 10;            //default size 10
    const int COLUMNS = 10;            //default size 10

    char emptyGrid[ROWS][COLUMNS];      // Array of random numbers for randomized ship placement
    char boardHidden[ROWS][COLUMNS];   // Array with assigned ship locations from emptyGrid
    char displayBoard[ROWS][COLUMNS];   // Array that displays current locations of misses and hits

    char guessX;     // X (column) guess
    int guessY;     // Y (row)guess


    PlaceShips();       // Makes a board of randomly generated values where ships are placed

    InitGrid(emptyGrid);        // Creates a play grid based on the ship placements from PlaceShips

    do{   //Main game loops until finished or X guesses are completed

        cout << "Data collection prompt\n";     // Requests and collects user guess values
        cin >> guessX;
        cin >> guessY;

        void HitMiss(boardHidden, guessX, guessY);      // Tests if they hit or missed the ship

        void PrintGrid(displayBoard);       // Prints the grid using only water, hit and miss marks

        cout << "Track number of ships here";       // Code to track number of ships left

        attempts++;     // Increments attempts after each guess iteration

    }while(attempts<MAX_ATTEMPTS || shipCount == 0);

    cout << "Game over message";       // End game and display Victory or Defeat message

    return 0;
}
*/
