#pragma once
#include <models/Hitboxes/hitbox.hpp>
#include <iostream>

class ICollidable{
public:
  ICollidable(bool movabble, Hitbox &object_hitbox): is_movable(movabble), hitbox(object_hitbox){};
  Hitbox &hitbox; 
private:
  bool is_movable;
};
