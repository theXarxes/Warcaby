#include "nonHumanGame.h"
using namespace std;


nonHumanGame::nonHumanGame(Board *board) : Game(board) {
    PlayerPtr gracz1 = make_shared<HumanPlayer>(1);
    PlayerPtr gracz2 = make_shared<nonHumanPlayer>(2);
    gracz1->setBoard(board);
    gracz2->setBoard(board);
    gracze.push_back(gracz1);
    gracze.push_back(gracz2);
}

nonHumanGame::~nonHumanGame() {

}
