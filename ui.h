#ifndef UI_H
#define UI_H
#include <iostream>
#include "Caro.h"
using namespace std;

class ui:public Caro
{
private:
    void Init();
    void DrawBoard();
    void InputName1();
    void InputName2();
    void PlayMode();
    void DataMode();
    void ReplayMode();
    void PlayerEnd();
    void GetPlayer1Move();
    void GetPlayer2Move();
    void PlayerInput();
public:
    void Menu();
};

#endif // UI_H
