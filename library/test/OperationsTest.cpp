#include <boost/test/unit_test.hpp>
#include "Board.h"
#include "Operations.h"

BOOST_AUTO_TEST_SUITE(TestSuiteBoard)
    BOOST_AUTO_TEST_CASE(OperationsCurrentGame) {
        Board* S=new Board;
        Operations WG(S);
        for(int i=8;i>=1;i--)
        {
            for(int j=1;j<9;j++)
            {
                Field cos(j, i,false);
                S->getWholeBoard().push_back(cos);
            }
        }
        BOOST_TEST(WG.currentGame()==false);
        delete S;
    }

BOOST_AUTO_TEST_SUITE_END()
