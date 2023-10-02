#include "jumper.h"
#include <algorithm>

using namespace std;

Jumper::Jumper() {
}

/* Check if animal p can jump over a river
   The 'steps' argument is used to control how many river cells to test.
   Call isJumpable(board, p, y, x, 2) to test if p can do a horizontal river jump (2 steps)
   Call isJumpable(board, p, y, x, 3) to test if p can do a vertical river jump (3 steps)
   Return true if p can jump and false otherwise (e.g. due to blocking by a Rat in river)
 */
bool Jumper::isJumpable(Board* board, Piece* p, int y, int x, int steps) {
    /* TODO: Add code to check if p can jump over 'steps' river squares 
             to the destination(y, x) */

    //Call isJumpable(board, p, y, x, 2) to test if p can do a horizontal river jump (2 steps)
    //Call isJumpable(board, p, y, x, 3) to test if p can do a vertical river jump(3 steps)
    if (steps != 2 && steps != 3)
        return false;

    if (y == p->getY() && x == p->getX())
        return false;


    int newx = 0, newy = 0;

    if (steps == 2) {
        if (x < p->getX()) {
            newx = -1;
        }
        else
            newx = 1;
    }
    else
        newx = 0;

    if (steps == 3) {
        if (y < p->getY()) {
            newy = -1;
        }
        else
            newy = 1;
    }
    else
        newy = 0;


    for (int k = 1; k < steps + 1; k++){
    
        int aimx = p->getX() + k * newx;
        int aimy = p->getY() + k * newy;


        // false for the river have other animal like rat or it is not the river
        if (!board->isEmpty(aimy, aimx) || !board->isRiver(aimy, aimx))       
            return false;
        
    }

    Piece* checkp = board->get(y, x);

    if (checkp != EMPTY && !p->canCapture(checkp)) // cell affect by other hige rank animal
        return false;
    else
        return true;
    
}