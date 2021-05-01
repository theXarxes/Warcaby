#ifndef INTRODUCTIONPROJECT_FIELD_H
#define INTRODUCTIONPROJECT_FIELD_H
#include <memory>
#include <iostream>
#include <vector>
#include "Unit.h"


class Unit;
typedef std::shared_ptr<Unit> UnitPtr;

class Field {
private:
    int CoordinatesX;
    int CoordinatesY;
    bool Possesed;
    UnitPtr unit;
public:
    Field();
    Field(int coordinatesX, int coordinatesY, bool possesed);
    virtual ~Field();
///GETTERY I SETTERY
    int getCoordinatesX() const;
    int getCoordinatesY() const;
    bool isPossesed() const;
    void setPossesed(bool possesed);
    const UnitPtr &getUnit() const;
    void setUnit(const UnitPtr &unit);

///METODY

};


#endif //INTRODUCTIONPROJECT_FIELD_H
