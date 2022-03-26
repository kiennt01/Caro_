#ifndef REPLAY_H
#define REPLAY_H
#include <iostream>
#include <fstream>
#include "DataFile.h"
#include "Caro.h"

using namespace std;
class Replay:public Caro
{
private:
    ofstream input;
    Block Stored[100];
public:
    void LastGame(int, int);
    void ReadFileReplay(ifstream&, Block[], int&);
    void LoadCoordinate();

};

#endif // REPLAY_H
