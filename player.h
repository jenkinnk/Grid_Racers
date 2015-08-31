#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

#include "track.h"

using namespace std;

struct Position {
        int x;
        int y;
};
ostream& operator<< (ostream& out, Position p);

struct Velocity {
        int x;
        int y;
};
ostream& operator<< (ostream& out, Velocity v);

struct Move {
        int x;
        int y;
};

class Player{

public:
    Player();
	Player(char, istream& in, ostream& out);

	bool finished;

    char getNumber() const;
    void setNumber(char);

    int getMaxSpeed() const;
    void reduceMaxSpeed();

    Position getPosition() const;
    void setPosition (Position, Track&);

    Velocity getVelocity() const;
    void setVelocity (Velocity);

    void print(ostream&);

    void makeMove(Velocity, Track&); // assumes velocity has been updated
    char checkCollision();  // alters velocity & maxspeed if required
    int isLegal(Velocity, Track&);
    int codeFinder(Cell);
    //bool isProgressive(Velocity, Track&);

    void goToFinishLine(Track&);
    void setFinishLine(Position);
    Position getFinishLine();

private:
    Position position;
    Velocity velocity;
    int maxSpeed;
    char number;
    Position finishLine;

};

#endif // PLAYER_H_INCLUDED
