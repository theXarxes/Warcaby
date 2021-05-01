

#ifndef INTRODUCTIONPROJECT_NONHUMANPLAYER_H
#define INTRODUCTIONPROJECT_NONHUMANPLAYER_H
#include "Player.h"
#include <ctime>
#include <cstdlib>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>


class nonHumanPlayer: public Player {
public:
    nonHumanPlayer(int idPlayer);
    virtual ~nonHumanPlayer();
    virtual void move() override;
};


#endif //INTRODUCTIONPROJECT_NONHUMANPLAYER_H
