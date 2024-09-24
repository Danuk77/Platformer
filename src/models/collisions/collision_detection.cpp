#include "models/game_objects/transform.hpp"
#include "models/hitboxes/box_hitbox.hpp"
#include <collisions/collision_detection.hpp>

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
