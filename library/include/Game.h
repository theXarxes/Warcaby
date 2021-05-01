
#ifndef INTRODUCTIONPROJECT_GAME_H
#define INTRODUCTIONPROJECT_GAME_H
#include <string>
#include <memory>
#include "Board.h"
#include "nonHumanPlayer.h"
#include "HumanPlayer.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

class Board;
class Player;
typedef std::shared_ptr<Player> PlayerPtr;
class OptionsException : public std::logic_error{
public:
    explicit OptionsException(const std::string& what_arg ) : std::logic_error(what_arg){}
};
class Game {
protected:
    Board* board;
    std::vector<PlayerPtr> gracze;
public:
    Game(Board *board);
    ~Game();
    void Gra();
    void setBoard(Board *board);
    void currentBoard();
    bool currentGame();
    void save();
    void load();

    const std::vector<PlayerPtr> &getGracze() const;
};


#endif //INTRODUCTIONPROJECT_GAME_H
