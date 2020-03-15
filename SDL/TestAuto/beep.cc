#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <iostream>

int main(){
    //Initialize everything; including video and auto
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1) {
        std::cerr << "SDL_Int: " << SDL_GetError() << "\n";
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        std::cerr << "Mix_OpenAudio: " << Mix_GetError() << "\n";
    }

    Mix_Chunk *beepEffect = Mix_LoadWAV("beep-03.wav");
    Mix_PlayChannel(-1, beepEffect, 1);
    Mix_FreeChunk(beepEffect);
      

}
