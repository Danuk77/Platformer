#include "models/scene.hpp"
#include <memory>
#include <vector>

void Scene::add_game_object(std::unique_ptr<GameObject> object){
  scene_game_objects.push_back(std::move(object));
}

void Scene::render(){
  std::vector<std::unique_ptr<GameObject>>::iterator game_object_iterator;

  for(game_object_iterator = scene_game_objects.begin(); game_object_iterator != scene_game_objects.end(); game_object_iterator++){
    (*game_object_iterator)->render();
  }
}

int Scene::get_number_of_loaded_game_objects(){
  return scene_game_objects.size();
}
