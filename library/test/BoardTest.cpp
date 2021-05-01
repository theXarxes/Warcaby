#include <boost/test/unit_test.hpp>
#include "Board.h"

BOOST_AUTO_TEST_SUITE(TestSuiteBoard)

BOOST_AUTO_TEST_CASE(BoardConstructor) {
        Board board;
        BOOST_TEST(board.getWholeBoard().size() == 64);
        BOOST_TEST(board.getWholeUnits().size() == 24);
}

BOOST_AUTO_TEST_SUITE_END()
