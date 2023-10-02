#include <iostream>
#include <cctype>
#include "game.h"
#include "board.h"
#include "piece.h"
#include "elephant.h"
#include "lion.h"
#include "tiger.h"
#include "leopard.h"
#include "wolf.h"
#include "dog.h"
#include "cat.h"
#include "rat.h"
// TODO: include more necessary headers
#include "fileman.h"

using namespace std;

Board::Board(Game* game, char* filename) : 
    game(game), cells() {  // initalize cells' elements to nullptr
    // Set up the initial game board
    if (filename != nullptr)
        loadFromFile(filename, this);
    else
        init();
}

// initial gameboard configuration
void Board::init() {
    // TODO:
    // set up the Jungle chess standard initial gameboard properly;
    // add Elephants, Lions, ..., Rats to the cells array at correct positions 
    
    Piece* p;
    //blue
    p = new Rat(BLUE, 2, 0);
    put(2, 0, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Cat(BLUE, 1, 5);
    put(1, 5, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Dog(BLUE, 1, 1);
    put(1, 1, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Wolf(BLUE, 2, 4);
    put(2, 4, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Leopard(BLUE, 2, 2);
    put(2, 2, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Tiger(BLUE, 0, 6);
    put(0, 6, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Lion(BLUE, 0, 0);
    put(0, 0, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    p = new Elephant(BLUE, 2, 6);
    put(2, 6, p);
    getGame()->getPlayer(BLUE)->addPiece(p);
    //red
    p = new Rat(RED, 6, 6);
    put(6, 6, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Cat(RED, 7, 1);
    put(7, 1, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Dog(RED, 7, 5);
    put(7, 5, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Wolf(RED, 6, 2);
    put(6, 2, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Leopard(RED, 6, 4);
    put(6, 4, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Tiger(RED, 8, 0);
    put(8, 0, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Lion(RED, 8, 6);
    put(8, 6, p);
    getGame()->getPlayer(RED)->addPiece(p);
    p = new Elephant(RED, 6, 0);
    put(6, 0, p);
    getGame()->getPlayer(RED)->addPiece(p);

    // TODO: also add the created pieces to each player's vector of pieces
}




// Return true if (y, x) is an empty cell, and false otherwise
bool Board::isEmpty(int y, int x) {
    if (cells[y][x] == EMPTY)
        return true;
    return false;
}

// Return true if (y, x) is the den on the side of the specified color, 
// and false otherwise
bool Board::isDen(int y, int x, Color color) {
    // TODO: Add your code here
    //den is location at blue 0,3 and red is in 8,3
    if (x == 3) {//both x at 3
        if (color == BLUE) {//for blue
            if (y == 0)//y location
                return true;
        }
        else {//for red
            if (y == 8)//y location
                return true;
        }
    }

    return false;
}

// Return true if (y, x) is a trap on the side of the specified color, 
// and false otherwise
bool Board::isTrap(int y, int x, Color color) {
    // TODO: Add your code here
    //trap location blue is (0,2),(0,4),(1,3)
    //red is (8,2),(8,4),(7,3)
    if (color == 0) {//BLUE
        if ((x == 3 && y == 1) || (x == 2 && y == 0) || (x == 4 && y == 0))
            return true;
    }
    else {//RED
        if ((x == 3 && y == 7) || (x == 2 && y == 8) || (x == 4 && y == 8))
            return true;
    }
    return false;
}

// Return true if (y, x) is a river cell, and false otherwise
bool Board::isRiver(int y, int x) {
    return y >= 3 && y <= 5 && (x >= 1 && x <= 2 || x >= 4 && x <= 5);
}

// Get a piece from the specified cell
Piece* Board::get(int y, int x){
    if (0 <= y && y < H && 0 <= x && x < W)
        return cells[y][x];
    return OUT_BOUND; // out of bound
}

// Put piece p onto the specified cell
void Board::put(int y, int x, Piece* p){
    cells[y][x] = p;
    if (p != EMPTY) {
        p->setY(y);
        p->setX(x);
    }
}

 //Print the gameboard
void Board::print() {
    // TODO: Add code to print the HxW gameboard by looping over cells array
    // Hint: Make use of isEmpty(), isRiver(), isTrap(), isDen(), and 
    //       getLabel() of Piece to ease your work
    // Remember * for river cells, # for trap cells, X for den cells
    cout << "    A   B   C   D   E   F   G\n";
    for (int i = 0;i < 9;i++) {
        cout << "  +---+---+---+---+---+---+---+\n" << i + 1<<" |";
        for (int j = 0;j < 7;j++) {
            // Board content
            if (get(i, j) != nullptr){
                // Print the piece label
                cout <<" "<< get(i, j)->getLabel()<<" |";
            }
            else
            {
                // Print the river trap den

                if (isTrap(i, j, BLUE) || isTrap(i, j, RED))
                    cout << " # |";               
                else if (isRiver(i, j))
                    cout << " * |";
                else if (isDen(i, j, BLUE) || isDen(i, j, RED))
                    cout << " X |";
                else if (isEmpty(i, j))
                    cout << "   |";
               
            }

        }
        cout << endl;

    }
    cout << "  +---+---+---+---+---+---+---+\n";







}



// Check if the move from (y1, x1) to (y2, x2) is valid
bool Board::isMoveValid(int y1, int x1, int y2, int x2) {
    // TODO:
    // check against invalid cases, for example,
    // - the source is an empty cell
    if (get(y1, x1) == EMPTY || get(y1, x1) == OUT_BOUND)
        return false;

    // - the source and destination are the same position
    if (x1 == x2&&y1 == y2  )
        return false;
    // - the destination is out of bound of the board (hint: use OUT_BOUND)
    if (get(y2, x2) == OUT_BOUND)
        return false;
    // - the source piece is not of same color of current turn of the game
    // (... and anymore ?)
    if (getGame()->getTurn() != get(y1, x1)->getColor())
        return false;
    // [Note: you can modify the following code if it doesn't fit your design]

    // Piece-specific validation
    if (get(y1, x1)->isMoveValid(this, y2, x2) == false)
        return false;

   // return true;
}

// Carry out the move from (y1, x1) to (y2, x2)
bool Board::move(int y1, int x1, int y2, int x2) {
    if (isMoveValid(y1, x1, y2, x2)) {
        get(y1, x1)->move(this, y2, x2);
        return true;
    }
    return false;
}

// Return the pointer to the Game object
Game* Board::getGame() const {
    return game;
}
