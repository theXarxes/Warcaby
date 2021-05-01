#ifndef INTRODUCTIONPROJECT_HUMANPLAYER_H
#define INTRODUCTIONPROJECT_HUMANPLAYER_H
#include "Player.h"


class HumanPlayer: public Player {
public:
    HumanPlayer(int idPlayer);
    virtual ~HumanPlayer();
    virtual void move() override;
};


#endif //INTRODUCTIONPROJECT_HUMANPLAYER_H
