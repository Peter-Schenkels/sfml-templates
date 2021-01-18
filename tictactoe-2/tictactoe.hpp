
#pragma once

#include <stdint.h>
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "command.hpp"
#include "board.hpp"
#include "entities.hpp"

#define GRID_SIZE 100


enum class GameType
{
    gui,
    cli
};


class TicTacToe
{
private:

    TicTacToeEntities turn = TicTacToeEntities::player_1;
    GameType game_type = GameType::cli;
    std::array<Command, 9> commands;
    unsigned int array_pointer = 0;

    sf::Texture cross;
    sf::Texture circle;
    sf::RectangleShape grid_cell;

    bool mouse_press = false;

public:
    // Default constructor
    TicTacToe() = default;
    // Updates the game for one full round
    void update();
    // Updates the game and draws the current game and listens for input
    void update(sf::Event event, sf::RenderWindow & window);
    // Returns the board
    Board get_board();
    // Add and checks wether the given position already exist and adds it to commands 
    bool add_to_commands(Command command);
    // Undoos a turn
    void execute_undo();
    // Set's gui or cli
    void set_game_type(GameType type);
    // Draws the field in the window
    void draw(sf::RenderWindow & window);

private:
    // Get mouse and keyboard input
    Command * get_input(sf::Event event, sf::RenderWindow & window);
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