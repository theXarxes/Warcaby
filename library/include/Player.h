#ifndef INTRODUCTIONPROJECT_PLAYER_H
#define INTRODUCTIONPROJECT_PLAYER_H
#include <memory>
#include "Board.h"


typedef std::shared_ptr<Unit> UnitPtr;
class Player {
private:
    int idPlayer;
    Board* board;
public:
    Player(int idPlayer);
    virtual ~Player();
    virtual void move()=0;
    int getIdPlayer() const;
    Board *getBoard() const;
    void setBoard(Board *board);

};


#endif //INTRODUCTIONPROJECT_PLAYER_H
