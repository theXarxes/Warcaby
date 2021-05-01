#include <boost/test/unit_test.hpp>
#include "HumanPlayer.h"
#include "nonHumanPlayer.h"

BOOST_AUTO_TEST_SUITE(TestSuitePlayer)

    BOOST_AUTO_TEST_CASE(PlayerConstructor) {
        HumanPlayer player(3);
        nonHumanPlayer player1(4);
        BOOST_TEST(player.getIdPlayer()+player1.getIdPlayer()==7);
    }

    BOOST_AUTO_TEST_CASE(PlayerActions) {
        HumanPlayer player(3);
        nonHumanPlayer player1(4);
        Board *board=new Board;
        player.setBoard(board);
        player1.setBoard(board);
        BOOST_TEST(player.getBoard() != nullptr);
        BOOST_TEST(player1.getBoard() != nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()