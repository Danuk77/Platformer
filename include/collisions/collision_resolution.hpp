#pragma once
#include "collisions/collision_report.hpp"
#include "models/game_objects/scene_object.hpp"

enum MinimumOverlapDirection{
  Horizontal,
  Vertial
};

void resolve_collision(SceneObject &player, CollisionReport &collision_report);
MinimumOverlapDirection find_direction_of_minimum_overlap(CollisionReport &report);
void resolve_against_direction_of_minimum_overlap(CollisionReport report, MinimumOverlapDirection direction, SceneObject &player);
