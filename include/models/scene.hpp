#pragma once
#include "models/game_object.hpp"
#include <vector>

class Scene{
public:
  Scene(){};
  void render();
  void add_game_object(GameObject object);
  int get_number_of_loaded_game_objects();
private:
  std::vector<GameObject> scene_game_objects; 
};
