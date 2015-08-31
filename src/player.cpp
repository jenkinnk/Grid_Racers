#include <iostream>

#include "player.h"

using namespace std;

inline
ostream& operator<< (ostream& out, Player p){
    p.print(out);
    return out;
};

inline
ostream& operator<< (ostream& out, Velocity v){
    out<<"("<<v.x<<","<<v.y<<")";
    return out;
};

inline
ostream& operator<< (ostream& out, Position p){
    out<<"("<<p.x<<","<<p.y<<")";
    return out;
};

Player::Player(char num, istream& in, ostream& out){
    maxSpeed = 5;
	position.x = 0;
	position.y = 0;
    velocity.x = 0;
    velocity.y = 0;
    number = num;
    finished = false;
};

char Player::getNumber() const{
    return number;
};

void Player::setNumber(char num){
    number = num;
};

int Player::getMaxSpeed() const{
    return maxSpeed;
};

void Player::reduceMaxSpeed(){
    int s = getMaxSpeed();

    if (s > 1)
    --maxSpeed;
};

Position Player::getPosition() const{
    return position;
};

void Player::setPosition (Position newPos, Track& t){
    t.board[position.x][position.y].player = '0';
    position = newPos;
    t.board[position.x][position.y].player = getNumber();
};

Velocity Player::getVelocity() const{
    return velocity;
};

void Player::setVelocity (Velocity newVel){
    velocity = newVel;
};

void Player::print(ostream& out){
    out<<number<<": "<<position<<" "<<velocity<<endl;
};

void Player::makeMove(Velocity v, Track& t){
    Position p = getPosition();

    t.board[p.x][p.y].player = '0';
    p.x += v.x;
    p.y += v.y;

    t.board[p.x][p.y].player = getNumber();
    setPosition(p, t);
};
/*
bool Player::isProgressive(Velocity v, Track& t){
    int current = t.board[position.x][position.y].distanceFromFinish;
    int newdist = t.board[v.x][v.y].distanceFromFinish;

    if (newdist <= current)
        return true;
    else
        return false;
};
*/
int Player::codeFinder(Cell c){
    int code;

    if(c.value == 'X' || c.value == 'x')
        code = 2;
    else if(c.player != '0')
        code = 1;
    else if(c.value == ' ' && c.player == '0')
        code = 0;
    else if(c.value == 'F'){
        code = 3;
        finished = true;}

    return code;
};
void Player::goToFinishLine(Track& t){
    setPosition(finishLine, t);
};

void Player::setFinishLine(Position p){
    finishLine = p;
};

Position Player::getFinishLine(){
    return finishLine;
};

int Player::isLegal(Velocity m, Track& t){
    Position p = getPosition();
    int code = 0;

    Cell c = t.board[p.x][p.y];

    //Positive x and y
    if (m.x == 0 && m.y == 0){
		//(0,0)
        code = 0;
    }
    if (m.x == 0 && m.y == 1){
		//(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 0 && m.y == 2){
		//(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
		//(0,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 0 && m.y == 3){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 0 && m.y == 4){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
		code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,4)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 0 && m.y == 5){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,4)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,5)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 1 && m.y == 0){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 1 && m.y == 1){
         //(1,1)
        p.x = p.x + 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 1 && m.y == 2){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 1 && m.y == 3){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,2)
        p.x = p.x + 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 1 && m.y == 4){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,2)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,4)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 2 && m.y == 0){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(2,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 2 && m.y == 1){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(2,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 2 && m.y == 2){
        //(1,1)
        p.y = p.y + 1;
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(2,2)
        p.x = p.x + 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 2 && m.y == 3){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(1,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(2,2)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(2,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 3 && m.y == 0){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 3 && m.y == 1){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,1)
        p.x = p.x + 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 3 && m.y == 2){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,2)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 4 && m.y == 0){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(4,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 4 && m.y == 1){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(4,1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 5 && m.y == 0){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(4,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(5,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }

    //Negative x
    if (m.x == -1 && m.y == 0){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == 1){
        //(-1,1)
        p.x = p.x - 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == 2){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == 3){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,2)
        p.x = p.x - 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == 4){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,2)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,4)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == 0){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == 1){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == 2){
        //(-1,1)
        p.x = p.x - 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,2)
        p.x = p.x - 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == 3){
        //(0,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,1)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,2)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,3)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -3 && m.y == 0){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -3 && m.y == 1){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,1)
        p.x = p.x - 1;
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -3 && m.y == 2){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,2)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,2)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -4 && m.y == 0){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
       //(-4,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -4 && m.y == 1){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,1)
        p.y = p.y + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-4,1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -5 && m.y == 0){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
       //(-4,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-5,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }

     //Negative y
    if (m.x == 0 && m.y == -1){
		//(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 0 && m.y == -2){
		//(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
		//(0,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 0 && m.y == -3){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

        //(0,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 0 && m.y == -4){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-4)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 0 && m.y == -5){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-4)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-5)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 1 && m.y == -1){
         //(1,-1)
        p.x = p.x + 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 1 && m.y == -2){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 1 && m.y == -3){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-2)
        p.x = p.x + 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 1 && m.y == -4){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-2)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-4)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 2 && m.y == -1){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 2 && m.y == -2){
        //(1,-1)
        p.x = p.x + 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-2)
        p.x = p.x + 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}

    }
    if (m.x == 2 && m.y == -3){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-2)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 3 && m.y == -1){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-1)
        p.x = p.x + 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 3 && m.y == -2){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(1,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,-2)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == 4 && m.y == -1){
        //(1,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,0)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(2,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(3,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(4,-1)
        p.x = p.x + 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }

     //Negative x & y
    if (m.x == -1 && m.y == -1){
        //(-1,-1)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == -2){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == -3){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-2)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -1 && m.y == -4){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(0,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-2)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-4)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == -1){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == -2){
        //(-1,-1)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-2)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -2 && m.y == -3){
        //(0,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-1)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-2)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-3)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -3 && m.y == -1){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-1)
        p.x = p.x - 1;
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,-1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -3 && m.y == -2){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-1,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-2)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,-2)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }
    if (m.x == -4 && m.y == -1){
        //(-1,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,0)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-2,-1)
        p.y = p.y - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-3,-1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
        //(-4,-1)
        p.x = p.x - 1;
        c = t.board[p.x][p.y];
        code = codeFinder(c);
        if (code == 3) {setFinishLine(p);} if (code != 0) {return code;}
    }

    return code;
};
