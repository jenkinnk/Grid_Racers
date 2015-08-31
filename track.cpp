#include <iostream>
#include <string>

#include "track.h"
#include "player.h"

using namespace std;

Track::Track(istream& in, ostream& out){
    //out<<"Track initiated!"<<endl;
    int MAX_W;
    int MAX_H;

    string line = "";
    int lineCount = 0;

    getline(in, line);
    while(in){
        if(lineCount == 0){
            MAX_W = line.length();

            }
        lineCount++;
        getline(in, line);
    }
    MAX_H = lineCount;


    in.clear();
    in.seekg(0, in.beg);
    //out<<"Pointer reset to top!"<<endl;

    board = new Cell*[MAX_W];


    for(int i = 0; i < MAX_W; i++){
        board[i] = new Cell[MAX_H];
    }


    setWidth(MAX_W);
    setHeight(MAX_H);
    char workArray[MAX_W];
    int y = MAX_H - 1;

    getline(in, line);
    while(in && y > -1){
            //for(int x = 0; x < MAX_W; x++){out<<workArray[x];}out<<endl;
            for(int x = 0; x < MAX_W; x++){workArray[x]=line[x];}
            for(int x = 0; x < MAX_W; x++){
                if(workArray[x]=='x'||workArray[x]=='X'||workArray[x]==' '){
                    board[x][y].value = workArray[x];
                    board[x][y].player = '0';
                    board[x][y].distanceFromFinish = -1;}
                if(workArray[x]=='F'){
                    board[x][y].value = workArray[x];
                    board[x][y].player = '0';
                    board[x][y].distanceFromFinish = 0;}
                if(workArray[x]== '1'){
                    board[x][y].player = workArray[x];
                    board[x][y].value = ' ';
                    board[x][y].distanceFromFinish = -1;}
                if(workArray[x]== '2'){
                    board[x][y].player = workArray[x];
                    board[x][y].value = ' ';
                    board[x][y].distanceFromFinish = -1;}
                if(workArray[x]== '3'){
                    board[x][y].player = workArray[x];
                    board[x][y].value = ' ';
                    board[x][y].distanceFromFinish = -1;}
            }
            y--;
            getline(in, line);
    }
    //printTrack(out);
    assessTrack(out);
    //out<<"Track assessed!"<<endl;
};

Track::~Track(){
    int w = getWidth();

    for(int i = 0; i < w; i++){
        delete board[i];
        }
};

int Track::getWidth(){
    return width;
};
void Track::setWidth(int w){
    width = w;
};

int Track::getHeight(){
    return height;
};

void Track::setHeight(int h){
    height = h;
};

void Track::printTrack(ostream& out){
    int w = getWidth();
    int h = getHeight();

    for(int y = h-1; y > -1; y--){
        for(int x = 0; x < w; x++){
            if (board[x][y].player != '0'){
                out<<board[x][y].player;
            }
            else
                out<<board[x][y].value;
        }
        out<<endl;
    }
};

void Track::assessTrack(ostream& out){
    int w = getWidth();
    int h = getHeight();
    int a = 1;
    int x = 0;
    int y = 0;

    int k;
    int toProcess = 1;

	Position p;

    Position workArray[25];


    while(toProcess > 0){
        k = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if (board[j][i].distanceFromFinish == (a-1)){
                    workArray[k].x = j;
                    workArray[k].y = i;
                    k++;
                }
            }
        }

        for(int i = 0; i < k; i++){
            p = workArray[i];
            x = p.x;
            y = p.y;

            //(0,1)
            ++y;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(1,1)
            ++x;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(1,0)
            --y;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(1,-1)
            --y;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(0,-1)
            --x;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(-1,-1)
            --x;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(-1,0)
            ++y;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }

            //(-1,1)
            ++y;
            if (board[x][y].distanceFromFinish == -1
                &&  board[x][y].value != 'x'
                &&  board[x][y].value != 'X'){
                board[x][y].distanceFromFinish = a;
                }
        }
    a++;
    toProcess = k;
    //out<<"One set assessed!"<<endl;
    }

};
