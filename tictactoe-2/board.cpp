#include "board.hpp"


Board::Board()
{
    for(unsigned int x = 0; x < 3; x++)
    {
        for(unsigned int y = 0; y < 3; y++)
        {
            board[x][y] = TicTacToeEntities::empty;
        }
    }
}

void Board::fill(std::array<Command, 9> commands, uint8_t array_pointer)
{
    for(uint8_t index = 0; index < array_pointer; index++)
    {
        board[commands[index].position_x][commands[index].position_y] = commands[index].turn;
    }
}

void Board::draw()
{
    int pointer = 0;
    for(uint8_t y = 0; y < 3; y++ )
    {
        for(uint8_t x = 0; x < 3; x++)
        {
            std::cout << static_cast<char>(board[x][y]) << " ";
            pointer++;
        }
        std::cout << std::endl;
    }
}