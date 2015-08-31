#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>

#include "track.h"
#include "computerPlayer.h"
#include "humanPlayer.h"

using namespace std;

class Game{

public:
    Game(istream& in, istream& input, ostream& out);

    Track T;

	computerPlayer computerPlayer1;
	humanPlayer humanPlayer2;
	computerPlayer computerPlayer3;

	void playGame(istream& in, istream& input, ostream& out);
	bool gameEnded();
	//int nextTurn();
	int getPlayCount();
	void setPlayCount(int);
	void assignStart();

private:
	int playCount;
};

#endif // GAME_H_INCLUDED
