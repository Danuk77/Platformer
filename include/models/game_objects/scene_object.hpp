#pragma once
#include "models/hitboxes/box_hitbox.hpp"
#include <models/game_objects/drawable_object.hpp>
#include <interfaces/collidable.hpp>

class SceneObject: public DrawableObject, ICollidable{
public:
  SceneObject(std::string object_name, Transform transform, std::string shader_name, std::string sprite_name, BoxHitbox hitbox);
  BoxHitbox get_hitbox();
private:
  BoxHitbox hitbox;
};
