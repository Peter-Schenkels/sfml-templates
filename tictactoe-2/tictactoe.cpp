#include "tictactoe.hpp"


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

void TicTacToe::update()
{
    draw();
    auto win = check_win();
    if(win != TicTacToeEntities::empty){
        std::cout << "Player: " << static_cast<char>(win) << " has won the match!" << std::endl;
        reset();
        return;
    }
    else if(win == TicTacToeEntities::empty && array_pointer >= 8)
    {
        std::cout << "It's a draw!" << std::endl;
        reset();
        return;
    }
    check_command();
    switch_turn();
}

Board TicTacToe::get_board()
{
    Board board;
    board.fill(commands, array_pointer);
    return board;
}


void TicTacToe::draw()
{
    Board board;
    board.fill(commands, array_pointer);
    board.draw();
}

void TicTacToe::switch_turn()
{
    if(turn == TicTacToeEntities::player_1)
    {
        turn = TicTacToeEntities::player_2;
    }
    else
    {
        turn = TicTacToeEntities::player_1;
    }
}

void TicTacToe::check_command()
{
    std::string command;
    std::cout << "It's player " << static_cast<char>(turn) << " his turn. (type turn or undo)" << std::endl;
    std::cout << "Command type: ";
    std::cin >> command;
    if(command  == "undo")
    {
        execute_undo();
    } 
    else if(command == "turn")
    {
        execute_turn();
    }
    else
    {
        std::cerr << "Unknown command" << std::endl;
        check_command();
    }
}

void TicTacToe::execute_undo()
{
    if(array_pointer != 0)
    {
        array_pointer--;
    }
    else
    {
        std::cout << "Can't undo any more times." << std::endl;
    }
}


int * TicTacToe::prompt_position()
{
    std::string x;
    std::string y;
    std::cout << "Position X: ";
    std::cin >> x;
    std::cout << "Position Y: ";
    std::cin >> y;
    int * positions = new int[2]{std::stoi(x), std::stoi(y)};
    return positions;
}

bool TicTacToe::add_to_commands(Command command)
{
    if(!check_duplicate(command))
    {
        commands[array_pointer] = command;
        array_pointer++;
        return true;
    }
    return false;
}

void TicTacToe::execute_turn()
{
    int * positions = prompt_position();       

    if(positions[0] > 2 || positions[1] > 2 || positions[0] < 0 || positions[1] < 0)
    {
        std::cerr << "Invalid position" << std::endl;
        check_command();
    }
    else
    {        
        Command command(turn, positions[0], positions[1]);
        if(!add_to_commands(command))
        {
            std::cerr << "Move has already been made..." << std::endl;
            check_command();
        }
    }
}

bool TicTacToe::check_duplicate(Command command)
{
    for(unsigned int index = 0; index < array_pointer; index++)
    {
        if(command == commands[index])
        {
            return true;
        }
    }
    return false;
}

TicTacToeEntities TicTacToe::check_win()
{
    Board board;
    board.fill(commands, array_pointer);

    for(unsigned int x = 0; x < 3; x++)
    {
        TicTacToeEntities player = board.board[x][0];
        if(player != TicTacToeEntities::empty)
        {
            if(board.board[x][0] == player && board.board[x][1] == player && board.board[x][2] == player)
            {
                return player;
            }
        }
    }
    for(unsigned int y = 0; y < 3; y++)
    {
        TicTacToeEntities player = board.board[0][y];
        if(player != TicTacToeEntities::empty)
        {
            if(board.board[0][y] == player && board.board[1][y] == player && board.board[2][y] == player)
            {
                return player;
            }
        }
    }
    {
        TicTacToeEntities player = board.board[0][0];
        if(player != TicTacToeEntities::empty)  
        {
            if
            (
                (board.board[0][0] == player && 
                board.board[1][1] == player && 
                board.board[2][2] == player) 
            )
            {
                return player;
            }
        }

        player = board.board[2][0];
        if(player != TicTacToeEntities::empty)  
        {            
            if
            (      
                (board.board[2][0] == player && 
                board.board[1][1] == player && 
                board.board[0][2] == player)
            )
            {
                return player;
            }
        }
    }
    
    return TicTacToeEntities::empty;
}

void TicTacToe::reset()
{
    array_pointer = 0;
    turn = TicTacToeEntities::player_1;
}

