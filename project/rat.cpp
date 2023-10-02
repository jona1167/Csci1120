#include "rat.h"
#include <iostream>

using namespace std;

Rat::Rat(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[RAT-1]);
    setRank(RAT);
}

bool Rat::isMoveValid(Board* board, int y, int x) {
    // TODO: Override the superclass version of valid move checks
    // e.g., to allow a Rat to move into a square occuppied by an Elephant 
    //       to allow a Rat to enter a water square

    if (abs(getY() - y) + abs(getX() - x) != 1) // move other than 1 square
        return false;

    Piece *q = board->get(y, x);

   
    // e.g., to allow a Rat to move into a square occuppied by an Elephant 
    if (q != OUT_BOUND && q != EMPTY &&  !Rat::canCapture(q))
        return false;
    // it is outbound or not own den
    if (q == OUT_BOUND || board->isDen(y, x, getColor()))
        return false;
    //       to allow a Rat to enter a water square
    return true;
}

bool Rat::getisRiver(){//get private variable
    return isRiver;
}

void Rat::setisRiver(bool isRiver) {//get private variable
    
     this->isRiver=isRiver;
}

void Rat::move(Board* board, int y, int x){//store isRiver for capture use
    //set isRiver
    setisRiver(board->isRiver(y, x));
    Piece::move(board, y, x);
}

bool Rat::canCapture(Piece* p) {
    // TODO: Override the superclass version of capture checks
    // two case capture elephant or the same rank rat
    // A Rat can capture an Elephant
        // A Rat can capture an Elephant
    //as need to check is it in river so need to use isRiver() to check
     // A Rat can capture an Elephant only****on ground
    if (p->getRank() == ELEPHANT &&getisRiver()==false)
        return true;

    // A Rat can capture same rank rat undre river
    if ( p->getRank() == RAT && ((Rat*)p)->getisRiver()==true)//downcasting to call function
        return true;

    return getisRiver() == false && Piece::canCapture(p);
}