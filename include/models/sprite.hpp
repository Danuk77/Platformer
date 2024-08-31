#pragma once
#include <models/sprite_information.hpp>

class Sprite{
public:
  Sprite(){};
  Sprite(SpriteInformation loaded_sprite_information);
  void bind() const;
private:  
  unsigned int sprite_id;
};
