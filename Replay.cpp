#include "Replay.h"

using namespace std;

void Replay::LastGame(int iX, int iY)
{

    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Caro_Qt2\\CaroQt\\lastgame.text", ios::app);
    input << iX << " " << iY << endl;
    input.close();
}

void Replay::ReadFileReplay(ifstream& read, Block match[], int& count)
{
    count = 0;
    while (!read.eof())
    {
        read >> match[count].x >> match[count].y;
        count ++;
    }
}
void Replay::LoadCoordinate()
{
    int count;
    ifstream readFile("C:\\Users\\Admin\\Desktop\\cpp\\Caro_Qt2\\CaroQt\\lastgame.text");
    ReadFileReplay(readFile, Stored, count);
    if(readFile.is_open())
    {
    for(int i = 0; i < count; i++)
    {
        if (i % 2 == 0)
        {
            Player1Replay(Stored[i].x, Stored[i].y);
            cout << "check 1" << endl;
        }
        else if (i % 2 == 1)
        {
            Player2Replay(Stored[i].x, Stored[i].y);
            cout << "check 2" << endl;
        }
    }
    }
    else
    {
       cout << "Can not open file!" << endl;
    }

}
