#pragma once
#include <models/sprite_information.hpp>

class Sprite{
public:
  Sprite(){};
  Sprite(SpriteInformation loaded_sprite_information);
private:  
  static unsigned int VAO, VBO;
  unsigned int sprite_id;
};
