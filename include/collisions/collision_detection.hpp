#pragma once
/*
 * Module used for detecting collisions between different hitboxes
 */
#include "collisions/collision_report.hpp"
#include "models/game_objects/scene_object.hpp"
#include <interfaces/collidable.hpp>
#include <models/hitboxes/box_hitbox.hpp>

CollisionReport
determine_collision_between_scene_objects(SceneObject &scene_object_one,
                                          SceneObject &scene_object_two);
bool is_colliding(SceneObject &scene_object_one, SceneObject &scene_object_two);
CollisionReport create_collision_report(SceneObject &scene_object_one,
                                        SceneObject &scene_object_two);
float calculate_collision_penetration(float object_one_position,
                                      float hitbox_one_size,
                                      float object_two_position,
                                      float hitbox_two_size);
