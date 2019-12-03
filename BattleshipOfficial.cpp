#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

enum ORIENTATION{UP ,RIGHT ,DOWN ,LEFT};
enum OUTCOMES{HIT , MISS, SINK};

struct Position{
      int R;
      int C;
};
struct Ship{
    string name;
    int size;
    int healthPoints = size;
    Position shipPosition;
    ORIENTATION orientation;
    char sym;
};

const int NUM_ROWS = 10;
const int NUM_COLS = 10;
char HiddenBoard[NUM_ROWS][NUM_COLS];
Ship Destroyer,Submarine,Cruiser,Battleship,Carrier;
Ship shipList[5]{Destroyer,Submarine,Cruiser,Battleship,Carrier};

void FindShip();
void InsertShip(char HiddenBoard[][NUM_COLS]);
bool CheckSpace();
bool Announcements();

void InitBoard(/*OUT*/char PlayerBoard[][NUM_COLS]);
void PrintBoard(/*IN*/char PlayerBoard[][NUM_COLS]);
void InitializeShips(char HiddenBoard[NUM_ROWS][NUM_COLS]);
bool FindNumber(/*IN*/char HiddenBoard[][NUM_COLS], /*IN*/int guess, /*OUT*/ int &guessCol, /*out*/ int &guessRow);
void GuessLocation(/*IN*/int guessCol,/*IN*/ int guessRow);
int CompPickNumber(/*OUT*/ int guess);

int main(){
    int guessCol = 0;
    int guessRow = 0;
    char PlayerBoard[NUM_ROWS][NUM_COLS];
    char HiddenBoard[NUM_ROWS][NUM_COLS];

    bool found = false;

    srand(time(NULL));
    InitBoard(PlayerBoard); //initialize board
    InitBoard(HiddenBoard);

    PrintBoard(PlayerBoard);
    cout << endl;

    InitializeShips(HiddenBoard);
    PrintBoard(HiddenBoard);

//    FindShip(PlayerBoard, guessRow, guessCol);
//    CheckPos();
//    Announcements();
    return 0;
}

bool CheckSpace(int currShip){
    cout << "space";
    int i = 0;
    int size = shipList[currShip].size;
    int j = shipList[currShip].size-1;
    int R = shipList[currShip].shipPosition.R;
    int C = shipList[currShip].shipPosition.C;

    switch(shipList[currShip].orientation){
        case UP:
            cout << "up";
            if((R-j) < 0)
                return true;
            else
                return false;

        case DOWN:
            cout << "down";
            if((R+j) >=NUM_COLS)
                return true;
            else
                return false;

        case LEFT:
            cout << "left";
            if((C-j) < 0)
                return true;
            else
                return false;

        case RIGHT:
//            cout << "right C: " << shipList[currShip].shipPosition.C << " size: " << size;
            if(C+j >= NUM_COLS){
//                cout << "true";
                return true;}
            else
//                cout << "false";
                return false;
    }
}
//maybe switch
bool CheckOverlap(int currShip){

    cout << "overlap";
    int R = shipList[currShip].shipPosition.R;
    int C = shipList[currShip].shipPosition.C;
    int size = shipList[currShip].size;

    for(int i; i < shipList[currShip].size; i++){
        switch(shipList[currShip].orientation){
        case UP:
            for(int j = 0; j < size; j++){
                if(HiddenBoard[R - j][C] != '~'){
                    return true;
                }
            }
            return false;
        case DOWN:
            for(int j = 0; j < size; j++){
                if(HiddenBoard[R + j][C] != '~'){
                    return true;
                }
            }
            return false;
        case LEFT:
            for(int j = 0; j < size; j++){
                if(HiddenBoard[R][C - j] != '~'){
                    return true;
                }
            }
            return false;

        case RIGHT:
            for(int j = 0; j < size; j++){
                if(HiddenBoard[R][C + j] != '~'){
                    return true;
                }
            }
            return false;

        }
    }
}

void InsertShips(char HiddenBoard[NUM_ROWS][NUM_COLS]){

    int R = 0;
    int C = 0;
    bool space;
    bool overlap;

    for(int currShip = 0;currShip < 5;currShip++){

    //initialize ship
    do{
        shipList[currShip].shipPosition.R = rand()%NUM_COLS;
        shipList[currShip].shipPosition.C = rand()%NUM_COLS;
        R = shipList[currShip].shipPosition.R;
        C = shipList[currShip].shipPosition.C;
        shipList[currShip].orientation = ORIENTATION(rand()%4);
        cout << "-- reset --" << endl;
        space = CheckSpace(currShip);
        overlap = CheckOverlap(currShip);
    }while(space && overlap);

    switch(shipList[currShip].orientation){
        case UP:
            cout << "up";
            for(int j = 0; j<shipList[currShip].size; j++){
            HiddenBoard[R-j][C] = shipList[currShip].sym;
            cout << " U" << (R-j) << "U";
            }
            break;
        case DOWN:
            cout << "down";
            for(int j = 0; j<shipList[currShip].size; j++){
            HiddenBoard[R+j][C] = shipList[currShip].sym;
            cout << " D" << (R+j) << "D";
            }
            break;
        case LEFT:
            cout << "left ";
            for(int j = 0; j<shipList[currShip].size; j++){
            HiddenBoard[R][C-j] = shipList[currShip].sym;
            cout << " L" << (C-j) << "L";
            }
            break;
        case RIGHT:
            cout << " right";
            for(int j = 0; j<shipList[currShip].size; j++){
            HiddenBoard[R][C+j] = shipList[currShip].sym;
            cout <<  " R" << (C+j) << "R";
            }
            break;
        }
    }
}

void InitBoard(/*OUT*/char PlayerBoard[NUM_ROWS][NUM_COLS]){

         for(int i = 0; i < NUM_ROWS; i++){
          for(int j = 0; j < NUM_COLS; j++){
                PlayerBoard[i][j] = '~';
                HiddenBoard[i][j] = '~';
              }

          }
}

void PrintBoard(/*IN*/char PlayerBoard[NUM_ROWS][NUM_COLS]){
   for (int i = -1; i < NUM_ROWS; i++) //loop through row
    {
        cout << (i+1) << " ";
        for (int j = 0; j < NUM_COLS; j++){//loop through column
        if(i == -1){
            cout << char('A'+(j)) << " ";
        }else
            cout << PlayerBoard[i][j] << " ";
        }
        cout << endl;
    }
}

void InitializeShips(char HiddenBoard[NUM_ROWS][NUM_COLS]){
    for(int i = 0; i < 5; i++){
    switch(i){
    case 0:
        shipList[i].name = "Destroyer";
        shipList[i].size = 2;
        shipList[i].healthPoints = 2;
        shipList[i].sym = 'D';
        break;
    case 1:
        shipList[i].name = "Submarine";
        shipList[i].size = 3;
        shipList[i].healthPoints = 3;
        shipList[i].sym = 'S';
        break;
    case 2:
        shipList[i].name = "Cruiser";
        shipList[i].size = 3;
        shipList[i].healthPoints = 3;
        shipList[i].sym = 'R';
        break;
    case 3:
        shipList[i].name = "Battleship";
        shipList[i].size = 4;
        shipList[i].healthPoints = 4;
        shipList[i].sym = 'B';
        break;
    case 4:
        shipList[i].name = "Carrier";
        shipList[i].size = 5;
        shipList[i].healthPoints = 5;
        shipList[i].sym = 'A';
        break;
        }
    }
    InsertShips(HiddenBoard);
}
