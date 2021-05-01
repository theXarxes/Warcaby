#include "../include/Field.h"

Field::~Field() {

}

int Field::getCoordinatesX() const {
    return CoordinatesX;
}

int Field::getCoordinatesY() const {
    return CoordinatesY;
}

bool Field::isPossesed() const {
    return Possesed;
}



Field::Field(int coordinatesX, int coordinatesY, bool possesed) : CoordinatesX(
        coordinatesX), CoordinatesY(coordinatesY), Possesed(possesed) {}

void Field::setPossesed(bool possesed) {
    Possesed = possesed;
}

const UnitPtr &Field::getUnit() const {
    return unit;
}

void Field::setUnit(const UnitPtr &unit) {
    Field::unit = unit;
}





