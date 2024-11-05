#pragma once
#include <models/hitboxes/hitbox.hpp>

class BoxHitbox: public Hitbox{
public:
  BoxHitbox(float width, float height): hitbox_width(width), hitbox_height(height){};
  float hitbox_width;
  float hitbox_height;
};
