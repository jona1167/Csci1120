#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <array>
#include <vector>
#include "machine.h"
#include "game.h"
#include "board.h"

using namespace std;

Machine::Machine(string name, Color color) : Player(name, color) {
    // TODO: randomize the seed of random number generator 
    //       using the current time
    srand((unsigned)time(NULL));
}

// a sample machine that makes random valid moves
void Machine::makeMove(Board* board) {
    // TODO: make a random but valid move of a randomly picked piece on a board
    // Hint: there exist many ways to do so, one way is as follows:
    // - generate a random integer for picking a piece r from the player's pieces vector
    // - set y1, x1 to r->getY(), r->getX()
    // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
    //   [or better in the y, x range of the 4 neighboring cells around (y1, x1), note to
    //    handle jumpable cells, 2 or 3 cells away, as well for Tiger and Lion]
    // - call board's move(y1, x1, y2, x2)
    // - once a valid move is returned, print the from and to cell addresses 
    //   and exit this function
    // Note: it can happen that no valid move can be found despite repeated picks.
    //       For example, only a Rat remains alive at a corner of the board while 
    //       the two cells it may go have been occupied by a Cat and a Dog.
    //       In this case, the player must surrender (set the opponent as winner).

    vector<array<int, 3>> next;
    //next[][0] is piece
    //next[][1] is y
    // next[][1] is x
    // find all the valid step by each piece in the chess
    for (int i = 0; i < getPieceCount(); i++){
        Piece* p = getPiece(i);

        // Check for the surrounding 4 cells 4 case up down left right
        
        int tempx = p->getX(), tempy = p->getY();
            // if the move is valid then push in the vector
            if (p->isMoveValid(board, tempy -1, tempx))//up
                next.push_back({ i, tempy -1, tempx });            
            if (p->isMoveValid(board, tempy +1, tempx))//down
                next.push_back({ i, tempy +1, tempx });
            if (p->isMoveValid(board, tempy, tempx+1 ))//right
                next.push_back({ i, tempy, tempx+1  });
            if (p->isMoveValid(board, tempy, tempx-1))//left
                next.push_back({ i, tempy, tempx-1  });
            int checky = -1, checkx = -1;//-1 useless number
            // Special case for lion and tiger again 4 case up down left right
            if (p->getRank() == LION || p->getRank() == TIGER){              
                if (board->isRiver(tempy +1, tempx)){//up                   
                    checky = tempy + i * (3+1);// 3 steps jump
                    checkx = tempx;
                }
                else if (board->isRiver(tempy -1 , tempx)){//down                  
                    checky = tempy + i * (3 + 1);// 3 steps jump
                    checkx = tempx;
                }
                if (checky != -1 && checkx != -1){
                    if (p->isMoveValid(board, checky, checkx))//check it is valid
                        next.push_back({ i, checky, checkx });
                }
                checky = -1, checkx = -1;
                if (board->isRiver(tempy, tempx-1)){ //left                  
                    checky = tempy;
                    checkx = tempx + i * (2+1);// 2 steps jump
                }
                else if (board->isRiver(tempy, tempx + 1)){  //right                                  
                    checky = tempy;
                    checkx = tempx + i * (2 + 1);// 2 steps jump
                }
                if (checky != -1 && checkx != -1)
                {
                    if (p->isMoveValid(board, checky, checkx))//check it is valid
                        next.push_back({ i, checky, checkx });
                }
            }
        
    }

    //surrender
    if (!next.size()){
        board->getGame()->setState(GAME_OVER);
        //       In this case, the player must surrender (set the opponent as winner).
        if (getColor() == RED) {
            board->getGame()->setTurn(BLUE);
        }
        else
            board->getGame()->setTurn(RED);
        return;
    }
    int rannum = -1;
    rannum = rand() % next.size(); // [0,size]
    // - set y1, x1 to r->getY(), r->getX()
    //next[][0] is piece
    //next[][1] is y
    // next[][1] is x
    int x1 = -1, y1 = -1;
    x1 = getPiece(next[rannum][0])->getX();
    y1 = getPiece(next[rannum][0])->getY();
    board->move(y1, x1, next[rannum][1], next[rannum][2]);
    cout << this->getName() << "'s turn: " << (char)(x1 + 65) << y1 + 1 << " " << (char)(next[rannum][2] + 65) << next[rannum][1] + 1 << "\n";



}



