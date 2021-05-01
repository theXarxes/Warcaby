#include "Board.h"
using namespace std;
template<typename T, typename... Args>
void FoldPushBack(std::vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);
}

Board::Board() {
    for(int i=8;i>=1;i--)
    {
        for(int j=1;j<9;j++)
        {
            Field cos(j, i,false);
            FoldPushBack(getWholeBoard(),cos);
        }
    }
    for (int i = 0; i < 24; i++) {
        if (i <= 11) {
            UnitPtr cos1 = make_shared<Unit>(1, "1", i);
            getWholeUnits().push_back(cos1);

        } else {
            UnitPtr cos1 = make_shared<Unit>(2, "2", i);
            getWholeUnits().push_back(cos1);
        }
    }
    for (int i = 0; i < 64; i++) {
        if (getWholeBoard()[i].getCoordinatesX() == 1)
            getWholeBoard()[1].setPossesed(true);
            getWholeBoard()[1].setUnit(getWholeUnits()[0]);
            getWholeBoard()[3].setPossesed(true);
            getWholeBoard()[3].setUnit(getWholeUnits()[1]);
            getWholeBoard()[5].setPossesed(true);
            getWholeBoard()[5].setUnit(getWholeUnits()[2]);
            getWholeBoard()[7].setPossesed(true);
            getWholeBoard()[7].setUnit(getWholeUnits()[3]);
        if (getWholeBoard()[i].getCoordinatesX() == 2)
            getWholeBoard()[8].setPossesed(true);
        getWholeBoard()[8].setUnit(getWholeUnits()[4]);
        getWholeBoard()[10].setPossesed(true);
        getWholeBoard()[10].setUnit(getWholeUnits()[5]);
        getWholeBoard()[12].setPossesed(true);
        getWholeBoard()[12].setUnit(getWholeUnits()[6]);
        getWholeBoard()[14].setPossesed(true);
        getWholeBoard()[14].setUnit(getWholeUnits()[7]);
        if (getWholeBoard()[i].getCoordinatesX() == 3)
            getWholeBoard()[17].setPossesed(true);
        getWholeBoard()[17].setUnit(getWholeUnits()[8]);
        getWholeBoard()[19].setPossesed(true);
        getWholeBoard()[19].setUnit(getWholeUnits()[9]);
        getWholeBoard()[21].setPossesed(true);
        getWholeBoard()[21].setUnit(getWholeUnits()[10]);
        getWholeBoard()[23].setPossesed(true);
        getWholeBoard()[23].setUnit(getWholeUnits()[11]);
        if (getWholeBoard()[i].getCoordinatesX() == 6)
            getWholeBoard()[40].setPossesed(true);
        getWholeBoard()[40].setUnit(getWholeUnits()[12]);
        getWholeBoard()[42].setPossesed(true);
        getWholeBoard()[42].setUnit(getWholeUnits()[13]);
        getWholeBoard()[44].setPossesed(true);
        getWholeBoard()[44].setUnit(getWholeUnits()[14]);
        getWholeBoard()[46].setPossesed(true);
        getWholeBoard()[46].setUnit(getWholeUnits()[15]);
        if (getWholeBoard()[i].getCoordinatesX() == 7)
            getWholeBoard()[49].setPossesed(true);
        getWholeBoard()[49].setUnit(getWholeUnits()[16]);
        getWholeBoard()[51].setPossesed(true);
        getWholeBoard()[51].setUnit(getWholeUnits()[17]);
        getWholeBoard()[53].setPossesed(true);
        getWholeBoard()[53].setUnit(getWholeUnits()[18]);
        getWholeBoard()[55].setPossesed(true);
        getWholeBoard()[55].setUnit(getWholeUnits()[19]);
        if (getWholeBoard()[i].getCoordinatesX() == 8)
            getWholeBoard()[56].setPossesed(true);
        getWholeBoard()[56].setUnit(getWholeUnits()[20]);
        getWholeBoard()[58].setPossesed(true);
        getWholeBoard()[58].setUnit(getWholeUnits()[21]);
        getWholeBoard()[60].setPossesed(true);
        getWholeBoard()[60].setUnit(getWholeUnits()[22]);
        getWholeBoard()[62].setPossesed(true);
        getWholeBoard()[62].setUnit(getWholeUnits()[23]);
    }
}
Board::~Board() {}

 std::vector<Field> &Board::getWholeBoard()  {
    return wholeBoard;
}

 std::vector<UnitPtr> &Board::getWholeUnits() {
     return wholeUnits;
 }