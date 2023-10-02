#ifndef MACHINE_H
#define MACHINE_H
#include <array>
#include <vector>
#include "player.h"
using std::vector;
using std::array;
class Machine : public Player
{
public:
    Machine(string name, Color color);
    virtual void makeMove(Board* board);
    // ... more functions or data members if needed

};

#endif /* MACHINE_H */
