#ifndef LEO_H
#define LEO_H

#include "piece.h"

class Leopard : public Piece
{
public:
    Leopard(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
    virtual char getLabel() const;//for change the label to p not l
};

#endif /* LEO_H */
