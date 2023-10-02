#ifndef ELE_H
#define ELE_H

#include "piece.h"

class Elephant : public Piece
{
public:
    Elephant(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
    virtual bool canCapture(Piece* ptr);
};

#endif /* ELE_H */