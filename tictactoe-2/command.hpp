#pragma once
#include "entities.hpp"
#include <iostream>

class Command
{
public:

    TicTacToeEntities turn;
    uint8_t position_x;
    uint8_t position_y;

    Command() = default;
    Command( TicTacToeEntities u_turn, uint8_t u_position_x, uint8_t u_position_y);
    bool operator== ( const Command& rhs);
};