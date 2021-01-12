#include "chip8interpreter.hpp"



void Chip8Interpreter::initialize() 
{
    std::ifstream file;
    std::string line;
    file.open("games/TETRIS", std::ios::in);

    char buffer;
    unsigned int index = 0;
	while (!file.eof() ) {
        file.get(buffer);
        memory[index + 0x200] = buffer;  
        index++;
    }

    program_counter = 0x200;
    opcode = 0;
    address_register = 0;
    stack_pointer = 0;
    load_fontset_into_memory();
    clear_screen();
}

void Chip8Interpreter::load_fontset_into_memory()
{
    unsigned char chip8_fontset[] =
    { 
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    for(int i = 0; i < 80; ++i)
    {
        memory[i] = chip8_fontset[i];		
    }
}

void Chip8Interpreter::clear_screen()
{
    window.clear();
    for(int x = 0; x < SCREEN_SIZE_X; x++)
    {
        for(int y = 0; y < SCREEN_SIZE_Y; y++)
        {
            screen[x][y] = 0;
        }
    }
}

void Chip8Interpreter::update_timers()
{
    if(delay_timer > 0)
    {
        delay_timer--;
    }
    if(sound_timer > 0)
    {
        if(sound_timer == 1)
        {
            std::cout << "BEEP!\n";
        }
        sound_timer--;
    }  
}

void Chip8Interpreter::jump_address(unsigned short address)
{
    program_counter = address;
}

void Chip8Interpreter::call_address(unsigned short address)
{
    stack_pointer++;
    stack[stack_pointer] = program_counter;
    program_counter = address;
}


void Chip8Interpreter::return_from_subroutine()
{
    program_counter = stack[stack_pointer];
    stack_pointer--;
}

void Chip8Interpreter::skip_if_equal(unsigned short condition)
{
    unsigned char register_value = registers[(condition & 0x0F00) >> 8];
    unsigned char constant = condition & 0x00FF;
    if(register_value == constant)
    {
        program_counter += INSTRUCTION_INCREMENT;
    }
}

void Chip8Interpreter::skip_if_equal_register(unsigned short condition)
{
    unsigned char register_value_x = registers[(condition & 0x0F00) >> 8];
    unsigned char register_value_y = registers[(condition & 0x00F0) >> 4];
    if(register_value_x == register_value_y)
    {
        program_counter += INSTRUCTION_INCREMENT;
    }
}

void Chip8Interpreter::skip_if_not_equal_register(unsigned short condition)
{
    unsigned char register_value_x = registers[(condition & 0x0F00) >> 8];
    unsigned char register_value_y = registers[(condition & 0x00F0) >> 4];
    if(register_value_x != register_value_y)
    {
        program_counter += INSTRUCTION_INCREMENT;
    }
}

void Chip8Interpreter::skip_if_not_equal(unsigned short condition)
{
    unsigned char register_value = registers[(condition & 0x0F00) >> 8];
    unsigned char constant = condition & 0x00FF;
    if(register_value != constant)
    {
        program_counter += INSTRUCTION_INCREMENT;
    }
}

void Chip8Interpreter::assign_constant(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] = opcode && 0x0FF;
}

void Chip8Interpreter::assign_register(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] = registers[opcode && 0x0F0 >> 4];
}

void Chip8Interpreter::add_constant(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] += opcode && 0x0FF;
}

void Chip8Interpreter::or_register(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] |= registers[opcode & 0x00F0 >> 4];
}

void Chip8Interpreter::and_register(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] &= registers[opcode & 0x00F0 >> 4];
}

void Chip8Interpreter::xor_register(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] ^= registers[opcode & 0x00F0 >> 4];
}

void Chip8Interpreter::add_register(unsigned short opcode)
{
    registers[0xF] = (registers[(opcode & 0x0F00) >> 8] + registers[opcode & 0x00F0 >> 4]) > 255;
    registers[(opcode & 0x0F00) >> 8] += registers[opcode & 0x00F0 >> 4];
}

void Chip8Interpreter::sub_register(unsigned short opcode)
{
    registers[0xF] = registers[(opcode & 0x0F00) >> 8] > registers[opcode & 0x00F0 >> 4];
    registers[(opcode & 0x0F00) >> 8] -= registers[opcode & 0x00F0 >> 4];
}

void Chip8Interpreter::sub_register_n(unsigned short opcode)
{
    registers[0xF] = registers[(opcode & 0x0F00) >> 8] < registers[opcode & 0x00F0 >> 4];
    registers[(opcode & 0x0F00) >> 8] = registers[opcode & 0x00F0 >> 4] - registers[(opcode & 0x0F00) >> 8];
}

void Chip8Interpreter::shift_right(unsigned short opcode)
{
    registers[0xF] = (registers[(opcode & 0x0F00) >> 8] & 1) == 1;
    registers[(opcode & 0x0F00) >> 8] = registers[(opcode & 0x0F00) >> 8] >> 1;
}

void Chip8Interpreter::shift_left(unsigned short opcode)
{
    registers[0xF] = (registers[(opcode & 0x0F00) >> 8] & 128) == 1;
    registers[(opcode & 0x0F00) >> 8] = registers[(opcode & 0x0F00) >> 8] << 1;
}


void Chip8Interpreter::jump_address_v0(unsigned short address)
{
    program_counter = registers[0] + address;
}

void Chip8Interpreter::set_address_register(unsigned short value)
{
    address_register = value;
}

void Chip8Interpreter::register_random(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] = (rand() % 256) & ((opcode & 0x00FF)>> 8);
}

void Chip8Interpreter::draw(unsigned short opcode)
{
    window.clear();
    unsigned short x = registers[(opcode & 0x0F00) >> 8];
    unsigned short y = registers[(opcode & 0x00F0) >> 4];
    unsigned short height = opcode & 0x000F;
    unsigned short pixel;
    registers[0x7] = 0;
    for (int yline = 0; yline < height; yline++)
    {
        pixel = memory[address_register + yline];
        for(int xline = 0; xline < 8; xline++)
        {
            if((pixel & (0x80 >> xline)) != 0)
            {
                if(screen[x + xline][y + yline] == 1)
                    registers[0xF] = 1;                                 
                screen[x + xline][y + yline] ^= 1;
            }
        }
    }
    for(int x = 0; x < SCREEN_SIZE_X; x++)
    {
        for(int y = 0; y < SCREEN_SIZE_Y; y++)
        {
            int pixel_size = 1;
            sf::RectangleShape pixel;
            pixel.setPosition({ float(x * pixel_size), float(y * pixel_size)});
            pixel.setSize({(float)pixel_size, (float)pixel_size});
            window.draw(pixel);
        }
    }
}

bool Chip8Interpreter::get_key_press(unsigned char key)
{
    sf::Event event;
    window.pollEvent(event);
    if(event.type != sf::Event::KeyPressed)
    {
        return false;
    }
    switch(key)
            {
                case '1':
                    return event.key.code == sf::Keyboard::Num1;
                    break;
                case '2':
                    return event.key.code == sf::Keyboard::Num2;
                    break;
                case '3':
                    return event.key.code == sf::Keyboard::Num3;
                    break;
                case '4':
                    return event.key.code == sf::Keyboard::Q;
                    break;
                case '5':
                    return event.key.code == sf::Keyboard::W;
                    break;
                case '6':
                    return event.key.code == sf::Keyboard::E;
                    break;
                case '7':
                    return event.key.code == sf::Keyboard::A;
                    break;
                case '8':
                    return event.key.code == sf::Keyboard::S;
                    break;
                case '9':
                    return event.key.code == sf::Keyboard::D;
                    break;
                case '0':
                    return event.key.code == sf::Keyboard::X;
                    break; 
                case 'A':
                    return event.key.code == sf::Keyboard::Z;
                    break;
                case 'B':
                    return event.key.code == sf::Keyboard::C;
                    break;
                case 'C':
                    return event.key.code == sf::Keyboard::Num4;
                    break;
                case 'D':
                    return event.key.code == sf::Keyboard::R;
                    break;
                case 'E':
                    return event.key.code == sf::Keyboard::F;
                    break;
                case 'F':
                    return event.key.code == sf::Keyboard::V;
                    break;
            }
        return false;
}

void Chip8Interpreter::key_press(unsigned short opcode)
{
    unsigned char key = registers[(opcode & 0x0F00) >> 8];
    if(get_key_press(key))
    {
        program_counter += INSTRUCTION_INCREMENT;
    }
}

void Chip8Interpreter::key_not_press(unsigned short opcode)
{
    unsigned char key = registers[(opcode & 0x0F00) >> 8];
    if(!get_key_press(key))
    {
        program_counter += INSTRUCTION_INCREMENT;
    }
}

void Chip8Interpreter::set_delay_timer(unsigned short opcode)
{
    unsigned char time = registers[(opcode & 0x0F00) >> 8];
    delay_timer = time;
}

void Chip8Interpreter::set_sound_timer(unsigned short opcode)
{
    unsigned char time = registers[(opcode & 0x0F00) >> 8];
    sound_timer = time;
}

void Chip8Interpreter::get_delay_timer(unsigned short opcode)
{
    registers[(opcode & 0x0F00) >> 8] = delay_timer;
};

void Chip8Interpreter::add_address_register(unsigned short value)
{
    address_register += value;
}

void Chip8Interpreter::get_digit(unsigned short opcode)
{
    address_register = registers[(opcode & 0x0F00) >> 8] * 5;
}

void Chip8Interpreter::store_bcd(unsigned short opcode)
{
    unsigned char value = registers[(opcode & 0x0F00) >> 8];
    memory[address_register] = value % 100 / 10;
    memory[address_register+1] = value % 100;
    memory[address_register+2] = value % 10;

}

void Chip8Interpreter::store_registers(unsigned short opcode)
{
    unsigned char value = registers[(opcode & 0x0F00) >> 8];
    for(int i = 0; i < value; i++)
    {
        memory[address_register + i] = registers[i];
    }

}

void Chip8Interpreter::read_memory(unsigned short opcode)
{
    unsigned char value = registers[(opcode & 0x0F00) >> 8];
    for(int i = 0; i < value; i++)
    {
        memory[i] = registers[address_register + i];
    }

}

void Chip8Interpreter::wait_for_keypress(unsigned short opcode)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed)
        {
            return;
        }
    }
}


void Chip8Interpreter::cycle() 
{
    // Fetch opcode
    opcode = memory[program_counter] << 8 | memory[program_counter + 1];
    std::cout << std::hex << opcode << std::endl;
    unsigned short first_nibble = opcode & 0xF000;
    switch(first_nibble)
    {
        case 0x0000:
            switch(opcode)
            {
                case 0x00E0:
                    clear_screen();
                    break;
                case 0x00EE:
                    return_from_subroutine();
                    break;
            }
            program_counter += INSTRUCTION_INCREMENT;
            break;
        case 0x1000:
            jump_address(opcode & 0x0FFF);
            break;
        case 0x2000:
            call_address(opcode & 0x0FFF);
            break;
        case 0x3000:
            skip_if_equal(opcode);
            program_counter += INSTRUCTION_INCREMENT; 
            break;
        case 0x4000:
            skip_if_not_equal(opcode);
            program_counter += INSTRUCTION_INCREMENT; 
            break;
        case 0x5000:
            skip_if_equal_register(opcode);
            program_counter += INSTRUCTION_INCREMENT; 
            break;
        case 0x6000:
            assign_constant(opcode);
            program_counter += INSTRUCTION_INCREMENT; 
            break;
        case 0x7000:
            add_constant(opcode);
            program_counter += INSTRUCTION_INCREMENT; 
            break;
        case 0x8000:
            {
                unsigned short last_nibble = opcode & 0x000F;
                switch (last_nibble)
                {
                    case 0x000:
                        assign_register(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x001:
                        or_register(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x002:
                        and_register(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x003:
                        xor_register(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x004:
                        add_register(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x005:
                        sub_register(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x006:
                        shift_right(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                    case 0x007:
                        sub_register_n(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                    case 0x00E:
                        shift_left(opcode);
                        program_counter += INSTRUCTION_INCREMENT; 
                        break;
                }
            }
            break;
        case 0x9000:
            skip_if_not_equal_register(opcode);
            program_counter += INSTRUCTION_INCREMENT; 
            break;
        case 0xA000:
            set_address_register(opcode & 0x0FFF);
            program_counter += INSTRUCTION_INCREMENT;
            break;
        case 0xB000:
            jump_address_v0(opcode & 0x0FFF);
            break;
        case 0xC000:
            register_random(opcode);
            program_counter += INSTRUCTION_INCREMENT;
            break;
        case 0xD000:
            draw(opcode);
            program_counter += INSTRUCTION_INCREMENT;
            break;
        case 0xE000:
            {
            unsigned short last_nibble = opcode & 0x000F;
                switch (last_nibble)
                {
                    case 0x00E:
                        key_press(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                    case 0x001:
                        key_not_press(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                }
            }
            break;
        case 0xF000:
            {
            unsigned short third_nibble = opcode & 0x00F0;
            switch (third_nibble)
            {
                case 0x0000:
                    {
                        unsigned short last_nibble = opcode & 0x000F;
                        switch (last_nibble)
                        {
                            case 0x0007:
                                get_delay_timer(opcode);
                                program_counter += INSTRUCTION_INCREMENT;
                                break;
                            case 0x000A:
                                wait_for_keypress(opcode);
                                program_counter += INSTRUCTION_INCREMENT;
                                break;
                        }
                    }
                case 0x0010:
                    {
                        unsigned short last_nibble = opcode & 0x000F;
                        switch (last_nibble)
                            {
                                case 0x0005:
                                    set_delay_timer(opcode);
                                    program_counter += INSTRUCTION_INCREMENT;
                                    break;         
                                case 0x0008:
                                    set_sound_timer(opcode);
                                    program_counter += INSTRUCTION_INCREMENT;
                                    break;      
                                case 0x000E:
                                    add_address_register(opcode & 0x0F00);
                                    program_counter += INSTRUCTION_INCREMENT;
                                    break;       
                            }
                        }
                    break;
                    case 0x0020:
                        get_digit(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                    case 0x0030:
                        store_bcd(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                    case 0x0050:
                        store_registers(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                    case 0x0060:
                        read_memory(opcode);
                        program_counter += INSTRUCTION_INCREMENT;
                        break;
                }
            }
            break;
    }
    update_timers();
}