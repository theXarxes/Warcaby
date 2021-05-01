#include <iostream>
#include "Board.h"
#include "Game.h"
using namespace std;

int main()
{
    Board* board=new Board;
    Game game(board);
    game.Gra();
    delete board;
    return 0;
}