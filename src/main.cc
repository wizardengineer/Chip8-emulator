#include "chip8.h"
#include "SDL/Video.h"

int main(int argc, char *argv[]) {
    Chip8 Emulator;
    VideoGraphic();
    if(!argc == 2) {
        std::cerr << "Make sure to add the name of the file or ROM you want you want\n"
          << "Be ran by the Emulator\n";

        exit(1);
    }
    Emulator.initialize();
    Emulator.load(argv[1])


}

