#include "command.hpp"

Command::Command( TicTacToeEntities u_turn, uint8_t u_position_x, uint8_t u_position_y)
{
    turn = u_turn;
    position_x = u_position_x;
    position_y = u_position_y;    
}

bool Command::operator== ( const Command& rhs)
{ 
    return (position_x == rhs.position_x && position_y == rhs.position_y);
}
