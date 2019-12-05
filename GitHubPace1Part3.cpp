/*################################################################################################################
Group Pace1IsATerribleTeamName
Github Assignment #3
This stub program displays the pseudocode for the battleship game and utilizes a set of functions
to test the Initboard and Printboard functions which will print their results to screen.
################################################################################################################*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

enum ORIENTATION{DOWN, RIGHT};      // enum values for ship orientation
enum OUTCOMES{HIT , MISS, SINK};    // enum for guess results

struct Position{                    // struct for ship position
      int R;
      int C;
};

struct Ship{                        // Struct for ship
    string name;                    // Ship name
    int size;                       // Ship size
    int healthPoints = size;        // Health points for the ship
    Position shipPosition;          // Position struct for the ship
    ORIENTATION orientation;        // Orientation value for ship
    char sym;                       // Symbol for ship
};

const int NUM_ROWS = 10;            // Game row size
const int NUM_COLS = 10;            // Game column size
char HiddenBoard[NUM_ROWS][NUM_COLS];       // Global array for hidden board
Ship Destroyer,Submarine,Cruiser,Battleship,Carrier;        // Ship struct variables
Ship shipList[5]{Destroyer,Submarine,Cruiser,Battleship,Carrier};       // Array that tracks status of ships in game


void InsertShip(/*IN*/char HiddenBoard[][NUM_COLS], /*IN*/Ship shipType);       // Function to place ships on board
bool ShipErrorChecking(/*IN*/Ship shipType);      // Function to check ship placement is within bounds and without overlap
void InitBoard(/*OUT*/char PlayerBoard[][NUM_COLS]);        // Function to initialize gameboard
void PrintBoard(/*IN*/char PlayerBoard[][NUM_COLS]);        // Function to print gameboard
void InitializeShips(char HiddenBoard[NUM_ROWS][NUM_COLS]);     // Function to initialize ship formation and placement
void TestGuess (/*IN*//*OUT*/char HiddenBoard[NUM_ROWS][NUM_COLS], /*IN*/int guessCol, /*IN*/int guessRow);        // Function to test player guess against hidden board
void UpdateBoard(/*IN*//*OUT*/char HiddenBoard[NUM_ROWS][NUM_COLS], /*IN*//*OUT*/char PlayerBoard[NUM_ROWS][NUM_COLS], /*IN*/int guessCol, /*IN*/int guessRow);     // Function to update board

int main(){
    int guessCol = 0;       // Column guess value
    int guessRow = 0;       // Row guess value
    char PlayerBoard[NUM_ROWS][NUM_COLS];       // Main board template array

    srand(time(NULL));

    InitBoard(PlayerBoard);     // Call to initialize hidden and seeable board
    PrintBoard(PlayerBoard);        // Call to print visual board


    // While loop until game end conditions are met{
    // Prompt for guess
    // TestGuess(); Use function TestGuess against board values and print results to player
    // UpdateBoard(); Use function UpdateBoard to change hidden and printed board values based on results
    //}

    return 0;
}
// Checks position of ship on board
// Pre: Ships are placed on board in some form
// Post: Ships are placed on board in a valid manner
bool ShipErrorChecking(Ship shipType){

    int DownRow = shipType.shipPosition.R;
    int DownColumn = shipType.shipPosition.C;
    int RightRow = shipType.shipPosition.R;
    int RightColumn = shipType.shipPosition.C;

    switch(shipType.orientation){
        case DOWN:

            for(int j = 0; j<shipType.size; j++){       // Checks validity for the ship's vertical alignment
                if(HiddenBoard[DownRow+j][DownColumn] == '#'){
                    return true;
                }
            }
            return false;
            break;
        case RIGHT:

            for(int j = 0; j<shipType.size; j++){       // Checks validity for the ship's vertical alignment
                if(HiddenBoard[RightRow][RightColumn+j] == '#'){
                    return true;
            }
            return false;
    }
}
}

// Places ships on board
// Pre: A main board is created
// Post: Ships are placed on the board
void InsertShip(char HiddenBoard[NUM_ROWS][NUM_COLS], Ship shipType){

    int DownRow = 0;
    int DownColumn = 0;
    int RightRow = 0;
    int RightColumn = 0;

    switch(shipType.orientation = ORIENTATION(rand()%2)){

        case DOWN:      // Assigns a random place in the array for the ship's vertical alignment

            do{
            DownRow = rand()%(NUM_ROWS-(shipType.size-1));
            DownColumn = rand()%NUM_COLS;
            shipType.shipPosition.C = DownColumn;
            shipType.shipPosition.R = DownRow;
            }while(ShipErrorChecking(shipType));

            for(int j = 0; j<shipType.size; j++){
                HiddenBoard[DownRow+j][DownColumn] = '#';
                }
            break;

        case RIGHT:     // Assigns a random place in the array for the ship's horizontal alignment

            do{
            RightColumn = rand()%(NUM_COLS -(shipType.size - 1));
            RightRow = rand()%NUM_ROWS;
            shipType.shipPosition.C = RightColumn;
            shipType.shipPosition.R = RightRow;
            }while(ShipErrorChecking(shipType));

            for(int j = 0; j<shipType.size; j++){
                HiddenBoard[RightRow][RightColumn+j] = '#';
            }
    }
}

// Game boards are created with ships assigned
// Pre: n/a
// Post: Game boards are created with ships assigned
// in valid locations in proper positions
void InitBoard(/*OUT*/char PlayerBoard[NUM_ROWS][NUM_COLS]){

         for(int i = 0; i < NUM_ROWS; i++){
          for(int j = 0; j < NUM_COLS; j++){
                PlayerBoard[i][j] = '~';
                HiddenBoard[i][j] = '~';
              }
          }
    InitializeShips(HiddenBoard);
}

// Prints viewable game board to screen
// Pre: Game boards are created
// Post: Viewable game board is printed to screen
void PrintBoard(/*IN*/char PlayerBoard[NUM_ROWS][NUM_COLS]){
   cout << "Viewable board\n";
   for (int i = -1; i < NUM_ROWS; i++) //loop through row
    {
        if(i+1 < 10)
            cout <<" "  <<(i+1) << " " ;
        else
            cout << (i+1) << " ";
        for (int j = 0; j < NUM_COLS; j++){//loop through column
            if(i == -1){
                cout << char('A'+(j)) << " ";
            }else
                cout << PlayerBoard[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Hidden board\n";

    for (int i = -1; i < NUM_ROWS; i++) //loop through row
    {
        if(i+1 < 10)
            cout <<" "  <<(i+1) << " " ;
        else
            cout << (i+1) << " ";
        for (int j = 0; j < NUM_COLS; j++){//loop through column
            if(i == -1){
                cout << char('A'+(j)) << " ";
            }else
                cout << HiddenBoard[i][j] << " ";
        }
        cout << endl;
    }
}

// Ship objects are created to be placed on hidden board
// Pre: n/a
// Post: Ship objects are created to be placed on hidden board
void InitializeShips(/*IN*/char HiddenBoard[NUM_ROWS][NUM_COLS]){
    for(int i = 0; i < 5; i++){     // For loop to place each ship type
    switch(i){
    case 0:
        shipList[i].name = "Destroyer";
        shipList[i].size = 2;
        shipList[i].healthPoints = 2;
        shipList[i].sym = '2';
        break;
    case 1:
        shipList[i].name = "Submarine";
        shipList[i].size = 3;
        shipList[i].healthPoints = 3;
        shipList[i].sym = '3';
        break;
    case 2:
        shipList[i].name = "Cruiser";
        shipList[i].size = 3;
        shipList[i].healthPoints = 3;
        shipList[i].sym = 'C';
        break;
    case 3:
        shipList[i].name = "Battleship";
        shipList[i].size = 4;
        shipList[i].healthPoints = 4;
        shipList[i].sym = '4';
        break;
    case 4:
        shipList[i].name = "Carrier";
        shipList[i].size = 5;
        shipList[i].healthPoints = 5;
        shipList[i].sym = '5';
        break;
        }
        InsertShip(HiddenBoard,shipList[i]);        // Ships are placed on hidden board
    }
}
// Tests player guess against hidden board
// Pre: A hidden board exists
// Post: Guess results are presented to player and to hidden board for changes
void TestGuess (/*IN*/char HiddenBoard[NUM_ROWS][NUM_COLS],/*IN*/int guessCol, /*IN*/int guessRow){
        cout << "Test the guess\n";
}

// Ship objects are created to be placed on hidden board
// Pre: n/a
// Post: Objects are created to be placed on hidden board
void UpdateBoard(/*IN*//*OUT*/char HiddenBoard[NUM_ROWS][NUM_COLS], /*IN*//*OUT*/char PlayerBoard[NUM_ROWS][NUM_COLS],/*IN*/int guessCol, /*IN*/int guessRow){
        cout << "Update the hidden board objects\n";
}
