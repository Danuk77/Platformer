#pragma once
#include "models/game_objects/scene_object.hpp"
#include "models/game_objects/game_object.hpp"
#include <memory>
#include <vector>

typedef std::vector<std::unique_ptr<SceneObject>> CollidableObjects;

// TODO
void execute_physics_cycle();
CollidableObjects &broad_phase();
void narrow_phase(CollidableObjects &objects_to_check_collisions);
