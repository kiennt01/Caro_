#ifndef UI_CPP
#define UI_CPP
#include <string.h>
#include "ui.h"
#include "DataFile.h"
#include "Replay.h"

using namespace std;


void ui::Init(){
    for(int i = 0 ; i < COLUM; i++){
        for(int j = 0; j < ROW; j++)
        {
            gameTABLE[i][j] =' ';
        }
    }
}
void ui::DrawBoard()
{
    cout << Player1.name << " <X> - " << Player2.name << " <0>" << endl;
    cout << "    ";
        for (int iX = 0; iX < COLUM; iX++)
        {
            if(iX + 1 < 10)
            {
                cout << iX + 1 << "   ";
            }
            else
            {
                cout << iX + 1 << "  ";
            }
        }
        cout << endl;
        for (int iY = 0; iY < ROW; iY++){
            if (iY + 1 < 10)
            {
                cout << iY + 1 << " ";
            }
            else
            {
                cout << iY + 1;
            }
            for (int iX = 0; iX < COLUM; iX++){
                cout << "| " << gameTABLE[iX][iY] << " ";
            }
            cout << endl;
            cout << "   ";
            for (int iX = 0; iX < COLUM; iX++){
                cout << "----";
            }
            cout << endl;
        }
}
void ui::GetPlayer1Move()
{
    cout << Player1.name << " <X> - " << Player2.name << " <0>" << endl;
    int iX, iY;
    cout << Player1.name << "'s turn" << endl;
    cout << "Input x : "; cin >> iX;
    cout << "Input y : "; cin >> iY;
    Player1Move(iX, iY);
}
void ui::GetPlayer2Move()
{
    cout << Player1.name << " <X> - " << Player2.name << " <0>" << endl;
    int iX, iY;
    cout << Player2.name << "'s turn" << endl;
    cout << "Input x : "; cin >> iX;
    cout << "Input y : "; cin >> iY;
    Player2Move(iX, iY);
}
void ui::PlayerInput()
{
    if (CheckTurn()) {
        GetPlayer2Move();
    }
    else if (!CheckTurn()) {
        GetPlayer1Move();
    }
    system("cls");
}
void ui::InputName1()
{
    char name[100];
    cout << "Input player 1's name : ";
    cin >> name;
    strcpy(Player1.name, name);
}
void ui::InputName2()
{
    char name[100];
    cout << "Input player 2's name : ";
    cin >> name;
    strcpy(Player2.name, name);
}
void ui::PlayerEnd()
{
    if(checkGameOver() && CheckTurn())
    {
        cout << Player1.name << " win!" << endl;
    }
    else if(checkGameOver() && !CheckTurn())
    {
        cout << Player2.name << " win!" << endl;
    }
}
void ui::Menu()
{
    int choice;
    cout << "Welcome to Caro game!!!" << endl;
    cout << "1. Play New Game" << endl;
    cout << "2. Open Database" << endl;
    cout << "3. Replay" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your option : ";
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        PlayMode();
        break;
    case 2:
        DataMode();
        break;
    case 3: ReplayMode();break;
    case 0: exit(0);
    }
}
void ui::PlayMode()
{
    ui newgame;
    int choice;
    newgame.InputName1();
    newgame.InputName2();
    system("cls");
    newgame.Init();
    newgame.DrawBoard();
    do
    {
        newgame.PlayerInput();
        newgame.checkGameOver();
        newgame.DrawBoard();
    } while (newgame.checkGameOver() == false);
    newgame.PlayerEnd();
    newgame.UpdateInfo();
    newgame.WriteFileReplay();
    cout << "Press 1 to return main menu" << endl << "Press 0 to exit" << endl;
    cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1: Menu(); break;
    case 0: exit(0);
    }
}
void ui::DataMode()
{
    int choice;
    DataFile datafile;
    datafile.SortInfo();
    cout << "----" << endl;
    cout << "Type a name to see data and most suitable opponent : ";
    label:
    datafile.LoadRank();
    cout << "----" << endl;
    cout << "Press 0 to exit " << endl;
    cout << "Press 1 to find other player data " << endl;
    cout << "Press 2 to return main menu" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1 :
        cout << "Type player name: " ;
        goto label;
    case 2 :
        system("cls");
        Menu();
        break;
    case 0 : exit(0);
    }
}
void ui::ReplayMode()
{
    Replay rep;
    Init();
    DrawBoard();
    rep.LoadCoordinate();
}

#endif // UI_CPP
