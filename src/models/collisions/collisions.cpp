#include "models/gamemanager.hpp"
#include "models/scene.hpp"
#include <collisions/collisions.hpp>
#include <memory>
#include <vector>


void execute_physics_cycle(){
  CollidableObjects &objects_to_check_for_collisions = broad_phase();
  narrow_phase(objects_to_check_for_collisions);
}

// TODO: Implement a quad tree structure to prune objects to do collision detection on
CollidableObjects &broad_phase(){
  return Gamemanager::current_scene.scene_collidable_objects;
};

void narrow_phase(CollidableObjects &objects_to_check_collisions){
  for (std::unique_ptr<SceneObject> &scene_object: objects_to_check_collisions){
    //std::cout << scene_object->transform.position.x; 
  }
}
