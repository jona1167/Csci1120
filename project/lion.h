#ifndef LIO_H
#define LIO_H

#include "jumper.h"
#include "piece.h"

class Lion : public Piece, public Jumper
{
public:
    Lion(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
};

#endif /* LIO_H */