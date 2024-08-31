#include "models/scene.hpp"
#include <vector>

void Scene::add_game_object(GameObject object){
  scene_game_objects.push_back(object);
}

void Scene::render(){
  std::vector<GameObject>::iterator game_object_iterator;

  for(game_object_iterator = scene_game_objects.begin(); game_object_iterator != scene_game_objects.end(); game_object_iterator++){
    game_object_iterator->render();
  }
}

int Scene::get_number_of_loaded_game_objects(){
  return scene_game_objects.size();
}
