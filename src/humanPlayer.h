#ifndef HUMANPLAYER_H_INCLUDED
#define HUMANPLAYER_H_INCLUDED

#include <iostream>

#include "player.h"

using namespace std;

class humanPlayer{

public:
    humanPlayer(int, istream& input, ostream& out);

    Player human;

    void getNextMove(Track&, istream& input, ostream& out);
    void attemptMove(Velocity, Track&, ostream& out);
};


#endif // HUMANPLAYER_H_INCLUDED
