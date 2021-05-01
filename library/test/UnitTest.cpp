#include <boost/test/unit_test.hpp>
#include "Unit.h"

BOOST_AUTO_TEST_SUITE(TestSuiteUnit)

BOOST_AUTO_TEST_CASE(UnitConstructor) {
    Unit unit(1,"I",5);
    BOOST_TEST(unit.getUnitNr()==5);
}

    BOOST_AUTO_TEST_CASE(UnitActiosn) {
        Unit unit(1,"I",1);
        unit.setLook("O");
        BOOST_TEST(unit.getLook()=="O");
        unit.setIdPlayer(3);
        BOOST_TEST(unit.getIdPlayer()==3);
    }

BOOST_AUTO_TEST_SUITE_END()