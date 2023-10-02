#include "lion.h"
#include <iostream>

using namespace std;

Lion::Lion(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[LION - 1]);
    setRank(LION);
}

bool Lion::isMoveValid(Board* board, int y, int x) {
    //bool Jumper::isJumpable(Board* board, Piece* p, int y, int x, int steps)
    if (abs(getY() - y) + abs(getX() - x) != 1){ // move other than 1 square

        // vertical jump
        if (x == this->getX() && y != this->getY()){
        
            return isJumpable(board, this, y, x, abs(y - this->getY()) - 1);
        }

        // horizontal jump       
        else if (x != this->getX() && y == this->getY()){
        
            return isJumpable(board, this, y, x, abs(x - this->getX()) - 1);
        }
        else
            return false;
    }
    else//just move
        return Piece::isMoveValid(board, y, x);
}
