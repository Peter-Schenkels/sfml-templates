#pragma once

#include <stdint.h>
#include <array>
#include "entities.hpp"
#include "command.hpp"

class Board
{
public:

    TicTacToeEntities board[3][3];

    Board();
    void fill(std::array<Command, 9> commands, uint8_t array_pointer);
    void draw();
};