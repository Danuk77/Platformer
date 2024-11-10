#include "collisions/collision_report.hpp"
#include "glm/common.hpp"
#include "models/game_objects/transform.hpp"
#include "models/hitboxes/box_hitbox.hpp"
#include <collisions/collision_detection.hpp>

CollisionReport determine_collision_between_scene_objects(SceneObject &scene_object_one,
                                          SceneObject &scene_object_two) {
  bool are_hitboxes_colliding = is_colliding(scene_object_one, scene_object_two);
  if (are_hitboxes_colliding) {
    return create_collision_report(scene_object_one, scene_object_two);
  }
  return CollisionReport(false, .0f, .0f);
}

bool is_colliding(SceneObject &scene_object_one,
                  SceneObject &scene_object_two) {
  Transform object_one_transform = scene_object_one.transform;
  Transform object_two_transform = scene_object_two.transform;

  BoxHitbox object_one_hitbox = scene_object_one.get_hitbox();
  BoxHitbox object_two_hitbox = scene_object_two.get_hitbox();

  float object_one_right_edge_position_x =
      object_one_transform.position.x + object_one_hitbox.hitbox_width;
  float object_two_right_edge_position_x =
      object_two_transform.position.x + object_two_hitbox.hitbox_width;

  float object_one_bottom_edge_position_y =
      object_one_transform.position.y + object_one_hitbox.hitbox_height;
  float object_two_bottom_edge_position_y =
      object_two_transform.position.y + object_two_hitbox.hitbox_height;

  bool is_colliding_on_x_axis =
      (object_one_right_edge_position_x >= object_two_transform.position.x) &&
      (object_two_right_edge_position_x >= object_one_transform.position.x);

  bool is_colliding_on_y_axis =
      (object_one_bottom_edge_position_y >= object_two_transform.position.y) &&
      (object_two_bottom_edge_position_y >= object_one_transform.position.y);

  return is_colliding_on_x_axis && is_colliding_on_y_axis;
}

CollisionReport create_collision_report(SceneObject &scene_object_one,
                                        SceneObject &scene_object_two) {
  BoxHitbox object_one_hitbox = scene_object_one.get_hitbox();
  BoxHitbox object_two_hitbox = scene_object_two.get_hitbox();

  Transform object_one_transform = scene_object_one.transform;
  Transform object_two_transform = scene_object_two.transform;

  float x_penetration = calculate_collision_penetration(
      object_one_transform.position.x, object_one_hitbox.hitbox_width,
      object_two_transform.position.x, object_two_hitbox.hitbox_width);
  float y_penetration = calculate_collision_penetration(
      object_one_transform.position.y, object_one_hitbox.hitbox_height,
      object_two_transform.position.y, object_two_hitbox.hitbox_height);

  return CollisionReport(true, x_penetration, y_penetration);
}

float calculate_collision_penetration(float object_one_position,
                                      float hitbox_one_size,
                                      float object_two_position,
                                      float hitbox_two_size) {
  float distance = object_one_position - object_two_position;
  float minimum_non_collision_distance =
      (hitbox_one_size / 2) + (hitbox_two_size / 2);
  float penetration_level = minimum_non_collision_distance - glm::abs(distance);

  // If the distance is positive, the object position value is greater, hence we
  // can assume direction
  if (distance > 0) {
    return penetration_level;
  } else {
    return -penetration_level;
  }
}
