PACE program Part 2

1.	Data structures needed:
2D array for board (A-K, 1-9),
structures(The 5 ships are:  Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2)),
Linked lists for ships (nodes contain ship coordinates),
Pointers
High score board

2.	Functions:
Initialize board (fill array with tildes (~))
Print board
Insert ship into random location (5 ships)
	Error checking (ships cannot overlap, not on edge, not diagonal)
Find ships
Check coordinates
Damage announcements (hit/sunk/miss)

3.	Pseudocode

enum Orientation

struct PositionType

Struct Ship{
    ship size
    hp
    ship position
    orientation
}

// Function prototypes
// Functions that do stuff
void InitializeBoard();
void PrintBoard();
void InitializeShip();
void FindShip();
void CheckPos();
bool Announcements();

void BlockMichaelsMalware();

// Functions that help big functions do stuff
void ShipErrorChecking

Main(){
    InitializeBoard();
    PrintBoard();
    InitializeShip();
    FindShip();
    CheckPos();
    Announcements();

    BlockMichaelsMalware();
}
