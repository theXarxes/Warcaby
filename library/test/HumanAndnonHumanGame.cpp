#include <boost/test/unit_test.hpp>
#include "humanGame.h"
#include "nonHumanGame.h"
#include "Game.h"

BOOST_AUTO_TEST_SUITE(TestSuiteGame)

BOOST_AUTO_TEST_CASE(BoardConstructor) {
        Board* S=new Board;
        humanGame cos1(S);
        nonHumanGame cos2(S);
        BOOST_TEST(cos1.getGracze()[0]->getIdPlayer()==1);
        BOOST_TEST(cos1.getGracze()[1]->getIdPlayer()==2);
        BOOST_TEST(cos2.getGracze()[0]->getIdPlayer()==1);
        BOOST_TEST(cos2.getGracze()[1]->getIdPlayer()==2);
        delete S;
}

BOOST_AUTO_TEST_SUITE_END()