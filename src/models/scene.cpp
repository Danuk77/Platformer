#include "models/scene.hpp"
#include <memory>
#include <utility>
#include <vector>

void Scene::add_game_object(std::unique_ptr<DrawableObject> object){
  scene_game_objects.push_back(std::move(object));
}

void Scene::add_game_object(std::unique_ptr<SceneObject> object){
  scene_collidable_objects.push_back(std::move(object));
}

void Scene::add_game_object(std::unique_ptr<Player> object){
  player_object = std::move(object);
}

void Scene::render(){
  std::vector<std::unique_ptr<DrawableObject>>::iterator drawable_object_iterator;
  std::vector<std::unique_ptr<SceneObject>>::iterator collidable_object_iterator;

  for(drawable_object_iterator = scene_game_objects.begin(); drawable_object_iterator != scene_game_objects.end(); drawable_object_iterator++){
    (*drawable_object_iterator)->render();
  }

  for(collidable_object_iterator = scene_collidable_objects.begin(); collidable_object_iterator != scene_collidable_objects.end(); collidable_object_iterator++){
    (*collidable_object_iterator)->render();
  }

  player_object->render();
}

int Scene::get_number_of_loaded_game_objects(){
  return scene_game_objects.size();
}
