#include "tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[TIGER-1]);
    setRank(TIGER);
}

bool Tiger::isMoveValid(Board* board, int y, int x) {
    /* TODO: implement valid move check specific to a Tiger
       Hint: make use of the isJumpable() function inherited from Jumper
             to check if horizontal and vertical jump can be done */

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
