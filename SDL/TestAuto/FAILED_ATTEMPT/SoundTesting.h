#ifndef _SOUND_TEST
#define _SOUND_TEST

#include <SDL2/SDL.h>
#include <bits/stdc++.h>

class Audio {
  public:
      ~Audio();
      void load(const char* filename);
      void play();
  private:
      /*The SDL_AudioSpec structure is used to 
       * describe the format of some audio data*/
      SDL_AudioSpec wavSpec;
      uint32_t wavLength;
      uint8_t *wavBuffer;
      SDL_AudioDeviceID deviceID;
};

#endif
