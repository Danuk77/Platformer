#include "models/sprite_information.hpp"
#include <stb/stb_image.h>
#include <models/sprite.hpp>
#include <iostream>

Sprite::Sprite(SpriteInformation loaded_sprite_information) {
  glGenTextures(1, &sprite_id);

  glBindTexture(GL_TEXTURE_2D, sprite_id);
  glTexImage2D(GL_TEXTURE_2D, 0, loaded_sprite_information.sprite_colour_format,
               loaded_sprite_information.sprite_width,
               loaded_sprite_information.sprite_height, 0,
               loaded_sprite_information.sprite_colour_format, GL_UNSIGNED_BYTE,
               loaded_sprite_information.sprite_data);
  
  // set texture wrap and filter modes
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // unbind texture
  glBindTexture(GL_TEXTURE_2D, 0);

  // Free the loaded image data
  stbi_image_free(loaded_sprite_information.sprite_data);
}

void Sprite::bind() const{
  glBindTexture(GL_TEXTURE_2D, sprite_id);
}
