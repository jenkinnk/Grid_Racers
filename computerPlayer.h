#ifndef COMPUTERPLAYER_H_INCLUDED
#define COMPUTERPLAYER_H_INCLUDED

#include <iostream>

#include "player.h"

using namespace std;

class computerPlayer{

public:
    computerPlayer(int, istream& in, ostream& out);

    Player compy;

	void getNextMove(Track&, ostream& out);

    void attemptMove(Velocity, Track&, ostream& out);

    void moveSort(Velocity*, int&, Velocity, Track&);
};

#endif // COMPUTERPLAYER_H_INCLUDED
