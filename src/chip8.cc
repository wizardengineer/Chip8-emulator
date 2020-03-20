/*Resource I used: 
http://www.multigesture.net/
articles/how-to-write-an-emulator-chip-8-interpreter/

https://en.wikipedia.org/wiki/CHIP-8#Opcode_table

https://github.com/craigthomas/Chip8Assembler#mnemonic-table
http://devernay.free.fr/hacks/chip8/C8TECH10.HTM
*/
#include "chip8.h"

/*
Memory map of the Chip8 Emulator:
0x000-0x1FF - Chip 8 interpreter contains font set in emulator
0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
0x200-0xFFF - Program ROM and work RAM
*/
Chip8::~Chip8(){
    delete[] bufferholder;
}

void Chip8::load(std::string game){
    std::ifstream rom(game, std::ios::binary);
    if(!file.is_open){
      std::cerr << "Can't find the ROM("<< file 
        << ") you're looking for\n";
      exit(1);
    }

    std::uintmax_t bytesize = fs::file_size(game);
    uchar8 *bufferholder = new uchar8[bytesize];
    rom.close();
    
    rom.read(bufferholder, bytesize);
    
    // After the initializaton of function
    // Chip::initialize() the program counter
    // will start at 0x200
      
    for(int i = 0; i < bytesize; i++) {
        memory[i + pc] = bufferholder[i];
        
    }
}

void Chip8::initialize(){
    opcode {};
    I      {};
    pc     {0x200};
    DT     {};
    ST     {};
    sp     {};

    //Clearing display
    //Clearing stack
    for(int i = 0; i < 16; i++){
      stack[i] = 0x00;
    }
    //Clearing registers V0 - VF
    for(int i = 0; i < 16; i++){
        V[i] = 0x00;
    }
    //Clear memory
    for(int i = 0; i < 4096  ){
        memory[i] = 0x00;
    }
    //Initialize the fontset
    fontset[80] {
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
    }
    
    

    //Loading the fontset into memory; the first 80 bytes
    for(int i = 0; i < 80; i++){
        memory[i] = fontset[i];
  }
}
 
void Chip8::emulation(){
    // Fetching Opcode
    opcode = memory[pc] << 8 | memory[pc + 1];
    // Decoding Opcode
    switch(opcode & 0xF000){
      case 0xA000:
          I = opcode & 0x0FFF;
          pc += 2;
      break;

      case 0x0000:
      {
        switch(opcode & 0x000F) {
          case 0x00E0:
            memset(gfx, 0, sizeof(gfx));
            pc += 2
          break;

          case 0x00EE:
            --sp;
            pc = stack[sp];
        }
      
      }
      break;
      case 0x3000:
        pc += 4; 

      break;
      case 0x1000:
          stack[sp] = pc;
          ++sp;
          uint16_t jmp = opcode & 0x0FFF;
          pc = jmp;
      break;

      case 
      
      case 0x2000:
          stack[sp] = pc;
          ++sp;
          pc = opcode & 0x0FFF;
      break; 
      case 
      default:
        printf("UNKNOWN OPCODE: 0x%x\n", opcode);
    }
 
    // Update timers

}


