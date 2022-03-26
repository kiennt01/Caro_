
#include <string.h>
#include <windows.h>
#include "Caro.h"
#include "DataFile.h"
#include "Replay.h"

using namespace std;
DataFile datafile;
Caro::Caro()
{
   Player1.name;
    Player1.win = 0;
    Player1.lose = 0;
    Player1.draw = 0;
    Player2.name;
    Player2.win = 0;
    Player2.lose = 0;
    Player2.draw = 0;
}

void Caro::Player1Move(int ix, int iy)
{
    do
    {
        --ix;
        --iy;
    } while (((0 > ix) || (COLUM - 1 < ix)) || ((0 > iy) || (ROW - 1 < iy)) || checkExist(ix, iy));
    Grid.x = ix;
    Grid.y = iy;
    Data.push_back(Grid);
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {

            if (Grid.x == i && Grid.y == j) {
                gameTABLE[i][j] = 'X';
            }
        }
    }
}
void Caro::Player2Move(int ix, int iy)
{
    do
    {
        --ix;
        --iy;
    } while (((0 > ix) || (COLUM - 1 < ix)) || ((0 > iy) || (ROW - 1 < iy)) || checkExist(ix, iy));
    Grid.x = ix;
    Grid.y = iy;
    Data.push_back(Grid);
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {
            if (Grid.x == i && Grid.y == j) {
                gameTABLE[i][j] = 'O';
            }
        }
    }
}

bool Caro::checkExist(int x, int y)
{
    for (int i = 0; i < Data.size(); i++)
    {
        if (Data[i].x == x && Data[i].y == y)
        {
            cout << " Invalid move! " << endl;
            return true;
        }
    }
    return false;
}
bool Caro::checkHorizontal() {
    int row = Data[Data.size() - 1].x;
    int column = Data[Data.size() - 1].y;
    char check = gameTABLE[row][column];
    int count = 1;
    int j = column;
    while (j > 0) {
        j--;
        if (gameTABLE[row][j] == check)
        {
            count++;

            if (count == GameWoncondition) return true;
        }
        else break;
    }
    j = column;
    while (j < (COLUM - 1)) {
        j++;

        if (gameTABLE[row][j] == check)
        {
            count++;

            if (count == GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool Caro::checkCross() {
    int row = Data[Data.size() - 1].x;
    int colum = Data[Data.size() - 1].y;
    char check = gameTABLE[row][colum];
    int count = 1;
    int i = colum;
    while (i > 0) {
        i--;
        if (gameTABLE[i][colum] == check)
        {
            count++;
            if (count == GameWoncondition) return true;
        }
        else break;
    }
    i = colum;
    while (i < (ROW - 1)) {
        i++;
        if (gameTABLE[i][colum] == check)
        {
            count++;
            if (count == GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool Caro::CheckDiagonal1() {
    int row = Data[Data.size() - 1].x;
    int colum = Data[Data.size() - 1].y;
    char check = gameTABLE[row][colum];
    int count = 1;
    int i = row;
    int j = colum;
    while (j > 0 && i > 0) {
        i--;
        j--;
        if (gameTABLE[i][j] == check) {
            count++;
            if (count == GameWoncondition) return true;
        }
        else break;

    }
    i = row;
    j = colum;
    while ((i < (COLUM - 1)) && (j < (ROW - 1))) {
        i++;
        j++;
        if (gameTABLE[i][j] == check) {
            colum++;
            if (count == GameWoncondition) return true
                ;
        }
        else break;
    }
    return false;
}
bool Caro::CheckDiagonal2() {
    int row = Data[Data.size() - 1].x;
    int column = Data[Data.size() - 1].y;
    char check = gameTABLE[row][column];
    int count = 1;
    int i = row;
    int j = column;
    while ((i > 0) && (j < (ROW - 1))) {
        i--;
        j++;
        if (gameTABLE[i][j] == check) {
            count++;
            if (count == GameWoncondition) return true;
        }
        else break;

    }
    i = row;
    j = column;
    while ((i < (ROW - 1)) && (j > 0)) {
        i++;
        j--;
        if (gameTABLE[i][j] == check) {
            count++;
            if (count == GameWoncondition) return true
                ;
        }
        else break;
    }
    return false;
}
bool Caro::CheckDrawGame()
{
    if (Data.size() == (COLUM * ROW)) return true;
    return false;
}
bool Caro::checkGameOver() {

    if (checkCross() || checkHorizontal() || CheckDiagonal1() || CheckDiagonal2() || CheckDrawGame())
    {
        return true;
    }
    return false;
}
bool Caro::CheckTurn()
{
        if (Data.size() % 2 == 1)
        {
            return true;
        }
        else if (Data.size() % 2 == 0)
        {
            return false;
        }
}


void Caro::Player1Replay(int x, int y)
{
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {
            if (x == i && y == j) {
                gameTABLE[i][j] = 'X';
            }
        }
    }
}
void Caro::Player2Replay(int x, int y)
{
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {
            if (x == i && y == j) {
                gameTABLE[i][j] = 'O';
            }
        }
    }
}
double Caro::WinRate(int win, int lose, int draw)
{
    return (100 * win)/(win + lose + draw);
}
void Caro::UpdateInfo()
{
    if (checkGameOver() && CheckTurn())
    {
            Player1.win++;
            Player2.lose++;
            datafile.WriteFile(Player1.name, Player1.win, Player1.lose, Player1.draw);
            datafile.WriteFile(Player2.name, Player2.win, Player2.lose, Player2.draw);
    }
     else if (checkGameOver() && !CheckTurn())
    {
            Player2.win++;
            Player1.lose++;
            datafile.WriteFile(Player1.name, Player1.win, Player1.lose, Player1.draw);
            datafile.WriteFile(Player2.name, Player2.win, Player2.lose, Player2.draw);
    }
    else if (CheckDrawGame())
    {
        Player1.draw++;
        Player2.draw++;
        datafile.WriteFile(Player1.name, Player1.win, Player1.lose, Player1.draw);
        datafile.WriteFile(Player2.name, Player2.win, Player2.lose, Player2.draw);
    }
}
double Caro::getClosest(double var1, double var2, double target)
{
    if ((target - var1) >= (var2 - target))
        return var2;
    else
        return var1;
}
void Caro::WriteFileReplay()
{
    Replay rep;
    for (int i = 0; i < Data.size(); i++)
    {
        rep.LastGame(Data[i].x, Data[i].y);
    }

}
