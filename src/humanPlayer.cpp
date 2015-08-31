#include <iostream>
#include <cmath>

#include "humanPlayer.h"

using namespace std;

humanPlayer::humanPlayer(int num, istream& input, ostream& out):
    human(num, input, out){};

void humanPlayer::getNextMove(Track& t, istream& input, ostream& out){
    int x, y = 0;
    Velocity v;


    out<<"Desired change in velocity: ";
    if(!input.eof()){
    input>>x;
    input>>y;
    }
    else{
        x = 0;
        y = 0;
    }
    out<<endl;

    if((abs(x) == 1 && abs(y) == 1) || (abs(x)>1 || abs(y)>1)){
		out<<"Not a legal change in velocity"<<endl;
		v.x = 0;
		v.y = 0;
		attemptMove(v, t, out);
		return;
	}
	else if((abs(x) + abs(y) + abs(human.getVelocity().x) + abs(human.getVelocity().y)) > human.getMaxSpeed()){
        out<<"Car 2 cannot go that fast"<<endl;
		v.x = 0;
		v.y = 0;
		attemptMove(v, t, out);
		return;
	}
    else{
	v.x = x + human.getVelocity().x;
    v.y = y + human.getVelocity().y;

    attemptMove(v, t, out);
    }

};

void humanPlayer::attemptMove(Velocity v, Track& t, ostream& out){

    int result = human.isLegal(v, t);
    Velocity zeroV;
    zeroV.x = 0;
    zeroV.y = 0;

    if(result == 0){
        human.makeMove(v, t);
        human.setVelocity(v);
    }
    if(result == 1){
        out<<"Car 2 has bumped another car."<<endl;
        human.setVelocity(zeroV);//set velocity to zero
    }
    if(result == 2){
        out<<"Car 2 has struck a wall."<<endl;
        human.setVelocity(zeroV);//set velocity to zero
        human.reduceMaxSpeed(); //reduce max speed
    }
    if(result == 3){
        human.goToFinishLine(t);
        human.setVelocity(v);
    }
};
