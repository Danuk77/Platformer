#pragma once
#include "glad/glad.h"

struct SpriteInformation{
  unsigned char *sprite_data;
  int sprite_width;
  int sprite_height;
  int number_of_channels;
  GLenum sprite_colour_format;
};
