#!/bin/sh

#install sdl2
sudo apt install libsdl2-dev libsdl2-2.0-0 -y;

#install sdl image
sudo apt install libjpeg9-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y;

#install sdl mixer
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y;

#install sdl true type fonts
sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y;
