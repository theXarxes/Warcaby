
#include "Unit.h"



Unit::~Unit() {

}


int Unit::getIdPlayer() const {
    return idPlayer;
}

const std::string &Unit::getLook() const {
    return Look;
}



int Unit::getUnitNr() const {
    return unitNr;
}

Unit::Unit(int idPlayer, const std::string &look, int unitNr) : idPlayer(idPlayer), Look(look), unitNr(unitNr) {}

void Unit::setLook(const std::string &look) {
    Look = look;
}

void Unit::setIdPlayer(int idPlayer) {
    Unit::idPlayer = idPlayer;
}




