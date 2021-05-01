#include <boost/test/unit_test.hpp>
#include "Field.h"

BOOST_AUTO_TEST_SUITE(TestSuiteField)

    BOOST_AUTO_TEST_CASE(FiledConstructor) {
        Field field(3,4,1);
        BOOST_TEST(field.isPossesed()==1);
    }

    BOOST_AUTO_TEST_CASE(PlayerActions) {
        Field field(1,1,1);
        BOOST_TEST(field.getCoordinatesY()+field.getCoordinatesX()==2);
        field.setPossesed(0);
        BOOST_TEST(field.isPossesed()==0);
    }

BOOST_AUTO_TEST_SUITE_END()