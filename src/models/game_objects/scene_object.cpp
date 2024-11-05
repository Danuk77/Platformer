#include "models/game_objects/drawable_object.hpp"
#include "models/hitboxes/box_hitbox.hpp"
#include <models/game_objects/scene_object.hpp>

SceneObject::SceneObject(std::string object_name, Transform transform,
                         std::string shader_name, std::string sprite_name, BoxHitbox hitbox)
    : DrawableObject(object_name, transform, shader_name, sprite_name), ICollidable(false, hitbox), hitbox(hitbox){
}

BoxHitbox SceneObject::get_hitbox(){
  return hitbox;
}
