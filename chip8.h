#ifndef _CHIP8
#define _CHIP8
 
// This would be better (#include <bits/stdc++.h>)
 
#include <bits/stdc++.h>
#include "filesystem.h"

typedef unsigned char uchar8;
 
class Chip8{
public:
    void initialize();
    void emulation();
    void load(std::string game);
private:
    uint8_t V[16];
    uint16_t opcode;
    uint8_t memory[4096];
    uint16_t I;
    uint16_t pc;
    uint8_t gfx[64*32];
    std::streampos fileSize( const char* filePath );
    //Sound timer and Delay timer
    uint32_t DT;
    uint32_t ST;
    uint16_t stack[16]
    uint16_t sp;
    uint8_t keypad[16];
    uint8_t fontset[80];
    
 
};
 
#endif


