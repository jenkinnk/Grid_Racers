#include <iostream>

#include "game.h"

using namespace std;

Game::Game(istream& in, istream& input, ostream& out):
    T(in, out),
    computerPlayer1('1', in, out),
    humanPlayer2('2', input, out),
    computerPlayer3('3', in, out)
{
	setPlayCount(0);
};

void Game::playGame(istream& in, istream& input, ostream& out){
	//int p;
	bool status = false;
	assignStart();
	int play = 1;

	while(!status){
	//p = nextTurn();
    if(play == 1){
        T.printTrack(out);

        computerPlayer1.compy.print(out);
        humanPlayer2.human.print(out);
        computerPlayer3.compy.print(out);

        computerPlayer1.getNextMove(T, out);
        status = gameEnded();

        T.printTrack(out);
        humanPlayer2.human.print(out);
        humanPlayer2.getNextMove(T, input, out);
        status = gameEnded();

        computerPlayer3.getNextMove(T, out);
        status = gameEnded();

        play++;
    }
	if(play == 2){
        T.printTrack(out);

        computerPlayer1.compy.print(out);
        humanPlayer2.human.print(out);
        computerPlayer3.compy.print(out);

        humanPlayer2.getNextMove(T, input, out);
        status = gameEnded();

        T.printTrack(out);

        computerPlayer1.compy.print(out);
        humanPlayer2.human.print(out);
        computerPlayer3.compy.print(out);

        computerPlayer3.getNextMove(T, out);
        status = gameEnded();

        computerPlayer1.getNextMove(T, out);
        status = gameEnded();

        play++;
	}
    if(play == 3){
        computerPlayer3.getNextMove(T, out);
        status = gameEnded();

        computerPlayer1.getNextMove(T, out);
        status = gameEnded();

        T.printTrack(out);
        humanPlayer2.human.print(out);
        humanPlayer2.getNextMove(T, input, out);
        play = 1;
    }

    }

};

bool Game::gameEnded(){
	bool result = false;

	if (computerPlayer1.compy.finished || humanPlayer2.human.finished || computerPlayer3.compy.finished)
		result = true;

	return result;
};
/*
int Game::nextTurn(){
    int x = getPlayCount();

	//1,2,3
    if(x%9 == 0){
        ++x;
        setPlayCount(x);
		return 1;}
	if(x%9 == 1){
        ++x;
        setPlayCount(x);
		return 2;}
	if(x%9 == 2){
        ++x;
        setPlayCount(x);
		return 3;}
	//2,3,1
	if(x%9 == 3){
		++x;
        setPlayCount(x);
		return 2;}
	if(x%9 == 4){
	    ++x;
        setPlayCount(x);
		return 3;}
	if(x%9 == 5){
	    ++x;
        setPlayCount(x);
		return 1;}
	//3,1,2
	if(x%9 == 6){
	    ++x;
        setPlayCount(x);
		return 3;}
	if(x%9 == 7){
	    ++x;
        setPlayCount(x);
		return 1;}
	if(x%9 == 8){
        ++x;
        setPlayCount(x);
		return 2;}

    return 0;
};
*/
int Game::getPlayCount(){
	return playCount;
};

void Game::setPlayCount(int num){
	playCount = num;
};

void Game::assignStart(){
    Position p;
    int w = T.getWidth();
    int h = T.getHeight();


    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if (T.board[j][i].player != '0'){
                p.x = j; p.y = i;
                if(T.board[j][i].player == '1')
                    computerPlayer1.compy.setPosition(p, T);
                if(T.board[j][i].player == '2')
                    humanPlayer2.human.setPosition(p, T);
                if(T.board[j][i].player == '3')
                    computerPlayer3.compy.setPosition(p, T);
            }
        }
    }
};
