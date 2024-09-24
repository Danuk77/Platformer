#pragma once
/*
* Module used for detecting collisions between different hitboxes
*/
#include "models/game_objects/scene_object.hpp"
#include <models/hitboxes/box_hitbox.hpp>
#include <interfaces/collidable.hpp>

bool is_colliding(SceneObject &scene_object_one, SceneObject &scene_object_two);
