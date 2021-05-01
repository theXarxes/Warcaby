#ifndef INTRODUCTIONPROJECT_HUMANGAME_H
#define INTRODUCTIONPROJECT_HUMANGAME_H

#include "Game.h"

class humanGame :public Game{
public:
    humanGame(Board *board);
    virtual ~humanGame();
};


#endif //INTRODUCTIONPROJECT_HUMANGAME_H
