#include <iostream>
#include <cmath>

#include "computerPlayer.h"

using namespace std;

computerPlayer::computerPlayer(int num, istream& in, ostream& out):
    compy(num, in, out){};

void computerPlayer::getNextMove(Track& t, ostream& out){
    Velocity v;
    Velocity speedArray[5];
    int moveCount = 0;
    int maxSpeed = compy.getMaxSpeed();
    int speed;

    //(0,0);
    v.x = compy.getVelocity().x;
    v.y = compy.getVelocity().y;
    speed = abs(v.x) + abs(v.y);
    if (compy.isLegal(v, t) == 0 && (speed <= maxSpeed)){
        speedArray[moveCount] = v;
        moveCount++;
    }
    if(compy.isLegal(v, t) == 3 && (speed <= maxSpeed)){
        compy.goToFinishLine(t);
        return;
    }

    //(1,0);
    v.x = compy.getVelocity().x + 1;
    v.y = compy.getVelocity().y;
    speed = abs(v.x) + abs(v.y);
    if (compy.isLegal(v, t) == 0 && (speed <= maxSpeed)){
        speedArray[moveCount] = v;
        moveCount++;
    }
    if(compy.isLegal(v, t) == 3 && (speed <= maxSpeed)){
        compy.goToFinishLine(t);
        return;
    }

    //(0,1);
    v.x = compy.getVelocity().x;
    v.y = compy.getVelocity().y + 1;
    speed = abs(v.x) + abs(v.y);
    if (compy.isLegal(v, t) == 0 && (speed <= maxSpeed)){
        speedArray[moveCount] = v;
        moveCount++;
    }
    if(compy.isLegal(v, t) == 3 && (speed <= maxSpeed)){
        compy.goToFinishLine(t);
        return;
    }

    //(-1,0);
    v.x = compy.getVelocity().x - 1;
    v.y = compy.getVelocity().y;
    speed = abs(v.x) + abs(v.y);
    if (compy.isLegal(v, t) == 0 && (speed <= maxSpeed)){
        speedArray[moveCount] = v;
        moveCount++;
    }
    if(compy.isLegal(v, t) == 3 && (speed <= maxSpeed)){
        compy.goToFinishLine(t);
        return;
    }

    //(0,-1);
    v.x = compy.getVelocity().x;
    v.y = compy.getVelocity().y - 1;
    speed = abs(v.x) + abs(v.y);
    if (compy.isLegal(v, t) == 0 && (speed <= maxSpeed)){
        speedArray[moveCount] = v;
        moveCount++;
    }
    if(compy.isLegal(v, t) == 3 && (speed <= maxSpeed)){
        compy.goToFinishLine(t);
        return;
    }

    if(moveCount == 0){
    v = compy.getVelocity();
    attemptMove(v, t, out);
    }

    if(moveCount > 0){
        moveSort(speedArray, moveCount, v, t);
        v = speedArray[0];
        attemptMove(v, t, out);
    }

};

void computerPlayer::attemptMove(Velocity v, Track& t, ostream& out){

    int result = compy.isLegal(v, t);
    Velocity zeroV;
    zeroV.x = 0;
    zeroV.y = 0;

    if(result == 0){
        compy.makeMove(v, t);
        compy.setVelocity(v);
    }
    if(result == 1){
        out<<"Car "<<compy.getNumber();
        out<<" has bumped another car."<<endl;
        compy.setVelocity(zeroV);//set velocity to zero
    }
    if(result == 2){
        out<<"Car "<<compy.getNumber();
        out<<" has struck a wall."<<endl;
        compy.setVelocity(zeroV);//set velocity to zero
        compy.reduceMaxSpeed(); //reduce max speed
    }
    if(result == 3){
        compy.goToFinishLine(t);
        compy.setVelocity(v);
    }
};

void computerPlayer::moveSort(Velocity* speedArray, int& moveCount, Velocity v, Track& t){
    char number = compy.getNumber();
    Position p = compy.getPosition();
    Velocity temp;
    int x = compy.getVelocity().x;
    //int y = compy.getVelocity().y;

    if (number == '1'){

        int sortCount = 1;
        for(int i = 1; (i < moveCount)&&sortCount ; i++){
            sortCount = 0;
          for (int j=0; j < (moveCount -1); j++){
               if (((abs(x) + abs(speedArray[j+1].x)) > (abs(x) + abs(speedArray[j].x))))
                    /* && ((t.board[p.x + speedArray[j+1].x][p.y + speedArray[j+1].y].distanceFromFinish)
                    < (t.board[p.x + speedArray[j].x][p.y + speedArray[j].y].distanceFromFinish)))*/
                {
                    temp = speedArray[j];
                    speedArray[j] = speedArray[j+1];
                    speedArray[j+1] = temp;
                    sortCount = 1;
                }
            }
        }


        sortCount = 1;
        for(int i = 1; (i < moveCount)&&sortCount ; i++){
            sortCount = 0;
          for (int j=0; j < (moveCount -1); j++){
               if ((t.board[p.x + speedArray[j+1].x][p.y + speedArray[j+1].y].distanceFromFinish)
                    < (t.board[p.x + speedArray[j].x][p.y + speedArray[j].y].distanceFromFinish))
                {
                    temp = speedArray[j];
                    speedArray[j] = speedArray[j+1];
                    speedArray[j+1] = temp;
                    sortCount = 1;
                }
            }
        }

    }

    if (number == '3'){

        int sortCount = 1;
        for(int i = 1; (i < moveCount)&&sortCount ; i++){
            sortCount = 0;
          for (int j=0; j < (moveCount -1); j++){
               if (((abs(x) + abs(speedArray[j+1].x)) < (abs(x) + abs(speedArray[j].x))))
                    /* && ((t.board[p.x + speedArray[j+1].x][p.y + speedArray[j+1].y].distanceFromFinish)
                    < (t.board[p.x + speedArray[j].x][p.y + speedArray[j].y].distanceFromFinish)))*/
                {
                    temp = speedArray[j];
                    speedArray[j] = speedArray[j+1];
                    speedArray[j+1] = temp;
                    sortCount = 1;
                }
            }
        }

        sortCount = 1;
        for(int i = 1; (i < moveCount)&&sortCount ; i++){
            sortCount = 0;
          for (int j=0; j < (moveCount -1); j++){
               if ((t.board[p.x + speedArray[j+1].x][p.y + speedArray[j+1].y].distanceFromFinish)
                    < (t.board[p.x + speedArray[j].x][p.y + speedArray[j].y].distanceFromFinish))
                {
                    temp = speedArray[j];
                    speedArray[j] = speedArray[j+1];
                    speedArray[j+1] = temp;
                    sortCount = 1;
                }
            }
        }
    }

}
