#include "collisions/collision_detection.hpp"
#include "models/gamemanager.hpp"
#include "models/scene.hpp"
#include <collisions/collisions.hpp>
#include <memory>
#include <vector>

void execute_physics_cycle() {
  CollidableObjects &objects_to_check_for_collisions = broad_phase();
  narrow_phase(objects_to_check_for_collisions);
}

// TODO: Implement a quad tree structure to prune objects to do collision
// detection on
CollidableObjects &broad_phase() {
  return Gamemanager::current_scene.scene_collidable_objects;
};

void narrow_phase(CollidableObjects &objects_to_check_collisions) {
  Player &player_object = *Gamemanager::current_scene.player_object;
  for (std::unique_ptr<SceneObject> &collidable_object_pointer :
       objects_to_check_collisions) {
    bool is_colliding_with_player =
        is_colliding(*collidable_object_pointer, player_object);
  }
}
