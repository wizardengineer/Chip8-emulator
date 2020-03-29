#include <SDL2/SDL.h>

#define MUS_PATH "beep-03.wav"

void my_audio_callback(void *userdata, Uint8 *stream, int len);
int play();
