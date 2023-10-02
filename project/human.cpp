#include <iostream>
#include "human.h"
#include "game.h"
#include "board.h"

using namespace std;

Human::Human(string name, Color color) : Player(name, color) { }

void Human::makeMove(Board* board) {
    while (true) {
        cout << this->getName() <<  "'s turn: ";
        char c1, c2;    // columns letters
        int r1, r2;     // row indexes (begin at 1)
        cin >> c1 >> r1 >> c2 >> r2;
        // if input fails, reset cin's state, skip the buffer and try again
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid. Try again!" << endl;
            continue;
        }
        
        // ad hoc stop condition (surrender)
        if (c1 == 'Z' && c2 == 'Z' && r1 == 0 && r2 == 0) {
            board->getGame()->setState(GAME_OVER);
            // TODO: set opponent as winner, 
            // e.g. by flipping the turn (if you assumed the player 
            // making the last turn before game over is the winner)
            if (getColor() == BLUE) {
                board->getGame()->setTurn(RED);
            }
            else
                board->getGame()->setTurn(BLUE);
            
            return;
        }
        
        // TODO:
        // Convert r1, c1 and r2, c2 into integers y1, x1, y2, x2 
        int y1=-1, x1 = -1, y2 = -1, x2 = -1;
    
        // Convert r1, c1 and r2, c2 into integers y1, x1, y2, x2
        //A=65 Z=90 a=97 z=122
        if ((c1 >= 65 && c1 <= 90))
            x1 = c1 - 65;
        else if (c1 >= 97 && c1 <= 122)
            x1 = c1 - 97;

        y1 = r1 - 1;

        if ((c2 >= 65 && c2 <= 90))
            x2 = c2 - 65;
        else if (c2 >= 97 && c2 <= 122)
            x2 = c2 - 97;

        y2 = r2 - 1;
        
       




        bool valid = board->move(y1, x1, y2, x2);
        if (valid)
            break;
        cout << "Invalid. Try again!" << endl;
    }
}
