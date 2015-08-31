#include <iostream>
#include <fstream>

#include "game.h"

using namespace std;

int main (int argc, char** argv)
{
    if (argc == 1)
    {
      Game g(cin, cin, cout);
    }
    if (argc == 2)
    {
      ifstream track (argv[1]);
      Game g(track, cin, cout);
      g.playGame(track, cin, cout);
    }
    else
    {
      ifstream track    (argv[1]);
      ifstream input    (argv[2]);
      ofstream output   (argv[3]);
      Game g(track, input, output);
      g.playGame(track, input, output);
    }
  return 0;
}

