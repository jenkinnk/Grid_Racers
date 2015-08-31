#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED

#include <iostream>

using namespace std;

struct Cell {
    char value;
    char player;
    int distanceFromFinish;
};

class Track{

public:
    Track(istream& in, ostream& out);
    ~Track();
    Cell** board;
    int getWidth();
    void setWidth(int);
    int getHeight();
    void setHeight(int);

	void printTrack(ostream& out);


private:
    int width;
    int height;

    void assessTrack(ostream&);

};

#endif // TRACK_H_INCLUDED
