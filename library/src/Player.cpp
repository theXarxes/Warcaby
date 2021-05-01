
#include "Player.h"

Player::Player(int idPlayer) : idPlayer(idPlayer) {}
Player::~Player() {}
void Player::move() {}

int Player::getIdPlayer() const {
    return idPlayer;
}

Board *Player::getBoard() const {
    return board;
}

void Player::setBoard(Board *board) {
    Player::board = board;
}

