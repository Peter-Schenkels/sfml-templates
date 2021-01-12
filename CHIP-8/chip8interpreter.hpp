#ifndef __CHIP_8__
#define __CHIP_8__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

// 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
// 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
// 0x200-0xFFF - Program ROM and work RAM

#define MEMORY_SIZE 4096
#define SCREEN_SIZE_X 64
#define SCREEN_SIZE_Y 32
#define STACK_SIZE 16
#define INSTRUCTION_INCREMENT 2



class Chip8Interpreter 
{

private:

    sf::RenderWindow & window;
    unsigned short opcode;
    unsigned char memory[MEMORY_SIZE];
    unsigned char registers[16];
    unsigned short address_register;
    unsigned short program_counter;
    unsigned char keys[16];
    unsigned char screen[SCREEN_SIZE_X][SCREEN_SIZE_Y];
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[STACK_SIZE];
    unsigned short stack_pointer;

    void update_timers();
    void clear_screen();
    void load_fontset_into_memory();
    void return_from_subroutine();
    void jump_address(unsigned short address);
    void jump_address_v0(unsigned short address);
    void call_address(unsigned short address);
    void skip_if_equal(unsigned short condition);
    void skip_if_not_equal(unsigned short condition);
    void skip_if_equal_register(unsigned short condition);
    void skip_if_not_equal_register(unsigned short condition);
    void assign_constant(unsigned short opcode);
    void assign_register(unsigned short opcode);
    void add_constant(unsigned short opcode);
    void or_register(unsigned short opcode);
    void and_register(unsigned short opcode);
    void xor_register(unsigned short opcode);
    void add_register(unsigned short opcode);
    void sub_register(unsigned short opcode);
    void sub_register_n(unsigned short opcode);
    void shift_right(unsigned short opcode);
    void shift_left(unsigned short opcode);
    void set_address_register(unsigned short value);
    void register_random(unsigned short opcode);
    void draw(unsigned short opcode);
    bool get_key_press(unsigned char key);
    void key_press(unsigned short opcode );
    void key_not_press(unsigned short opcode );
    void wait_for_keypress(unsigned short opcode);
    void set_delay_timer(unsigned short opcode);
    void set_sound_timer(unsigned short opcode);
    void get_delay_timer(unsigned short opcode);
    void add_address_register(unsigned short value);
    void get_digit(unsigned short opcode);
    void store_bcd(unsigned short opcode);
    void store_registers(unsigned short opcode);
    void read_memory(unsigned short opcode);

    


public:

    Chip8Interpreter(sf::RenderWindow & window):
        window(window)
    {}

    void initialize();

    void cycle();

};

#endif