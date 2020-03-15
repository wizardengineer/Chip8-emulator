#include "SoundTesting.h"

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    Audio effect;
    effect.load("beep-03.wav");
    effect.play();

}
