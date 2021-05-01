#include <boost/test/unit_test.hpp>
#include "Game.h"


BOOST_AUTO_TEST_SUITE(TestSuiteGame)
    BOOST_AUTO_TEST_CASE(Zapisy) {
        Board* S=new Board;
        Game ZO(S);
        for(int i=8;i>=1;i--)
        {
            for(int j=1;j<9;j++)
            {
                Field cos(j, i,false);
                S->getWholeBoard().push_back(cos);
            }
        }

        ZO.save();
        std::ifstream otworz("zapis.txt");
        bool x=1;
        for(int i=0;i<64;i++){
            S->getWholeBoard()[i].setPossesed(false);
            otworz>>x;
            if(x==0){
            BOOST_TEST(S->getWholeBoard()[i].isPossesed()==x);}
        }
        otworz.close();
        ZO.load();
        BOOST_TEST(S->getWholeBoard()[0].isPossesed()==0);
        delete S;
    }

BOOST_AUTO_TEST_SUITE_END()