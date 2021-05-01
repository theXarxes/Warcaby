#ifndef INTRODUCTIONPROJECT_BOARD_H
#define INTRODUCTIONPROJECT_BOARD_H
#include "Field.h"
#include "Unit.h"
#include <memory>
#include <vector>


class Field;
class Unit;
typedef std::shared_ptr<Field> FieldPtr;
typedef std::shared_ptr<Unit> UnitPtr;

class Board {
private:
    std::vector<Field> wholeBoard;
    std::vector<UnitPtr> wholeUnits;
public:
    Board();
    ~Board();
     std::vector<Field> &getWholeBoard() ;
     std::vector<UnitPtr> &getWholeUnits() ;

};


#endif //INTRODUCTIONPROJECT_BOARD_H
