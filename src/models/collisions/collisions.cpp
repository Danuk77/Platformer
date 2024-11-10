#include "collisions/collision_detection.hpp"
#include "collisions/collision_report.hpp"
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

    if (collidable_object_pointer->object_name == "test_collision_object") {
      CollisionReport report = determine_collision_between_scene_objects(player_object, *collidable_object_pointer);

      if(report.is_colliding){
          std::cout << "Is colliding " << report.is_colliding
            << " collision depth x: " << report.collision_depth_x
            << " collision depth y: " << report.collision_depth_y
            << std::endl;
      }
    }
  }
}
