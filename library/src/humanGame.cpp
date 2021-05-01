#include "humanGame.h"
using namespace std;

humanGame::humanGame(Board *board) : Game(board) {
    PlayerPtr gracz1 = make_shared<HumanPlayer>(1);
    PlayerPtr gracz2 = make_shared<HumanPlayer>(2);
    gracz1->setBoard(board);
    gracz2->setBoard(board);
    gracze.push_back(gracz1);
    gracze.push_back(gracz2);
}

humanGame::~humanGame() {

}
