#ifndef CARO_H
#define CARO_H
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

#define  COLUM 10
#define  ROW 10
#define GameWoncondition 4
struct Block
{
    int x;
    int y;
};
struct Infor
{
    char name[50];
    int win;
    int lose;
    int draw;
};
class Caro
{
protected:
    char gameTABLE[COLUM][ROW];
    Infor Player1;
    Infor Player2;
    void Player1Move(int, int);
    void Player2Move(int, int);
    bool CheckDrawGame();
    bool checkExist(int x, int y);
    bool checkGameOver();
    void UpdateInfo();
private:
    Block Grid;
    vector<Block> Data;
    bool checkHorizontal();
    bool checkCross();
    bool CheckDiagonal1();
    bool CheckDiagonal2();
public:
    Caro();
    void WriteFileReplay();
    bool CheckTurn();
    void Player1Replay(int, int);
    void Player2Replay(int, int);
    double WinRate(int, int, int);
    double getClosest(double, double, double);
};

#endif // CARO_H
