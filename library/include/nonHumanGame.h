#ifndef INTRODUCTIONPROJECT_NONHUMANGAME_H
#define INTRODUCTIONPROJECT_NONHUMANGAME_H

#include "Game.h"

class nonHumanGame :public Game{
public:
    nonHumanGame(Board *board);

    virtual ~nonHumanGame();
};


#endif //INTRODUCTIONPROJECT_NONHUMANGAME_H
