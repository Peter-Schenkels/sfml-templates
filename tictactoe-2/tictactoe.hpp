
#pragma once

#include <stdint.h>
#include <iostream>
#include <array>

enum class TicTacToeEntities : char
{
    empty = '-',
    player_1 = 'x',
    player_2 = 'O'
};

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


class Board
{
public:

    TicTacToeEntities board[3][3];

    Board();
    void fill(std::array<Command, 9> commands, uint8_t array_pointer);
    void draw();
};

class TicTacToe
{
private:

    TicTacToeEntities turn = TicTacToeEntities::player_1;
    std::array<Command, 9> commands;
    unsigned int array_pointer = 0;

public:
    // Default constructor
    TicTacToe() = default;
    // Updates the game for one full round
    void update();
    // Returns the board
    Board get_board();
    // Add and checks wether the given position already exist and adds it to commands 
    bool add_to_commands(Command command);
    // Undoos a turn
    void execute_undo();

private:

    // Draws the field in the commandline
    void draw();
    // Switches player turn
    void switch_turn();
    // Checks wether the command is valid
    void check_command();
    // Prompts the player for a turn
    int * prompt_position();
    // Executes a command
    void execute_turn(); 
    // Checks wether the given command's position already exist in the commands array
    bool check_duplicate(Command command);
    // Checks board for wins
    TicTacToeEntities check_win();
    // Resets the commands
    void reset();
};