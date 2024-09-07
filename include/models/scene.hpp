#pragma once
#include "models/game_objects/game_object.hpp"
#include <memory>
#include <vector>

class Scene{
public:
  Scene(){};
  void render();
  void add_game_object(std::unique_ptr<GameObject> object);
  int get_number_of_loaded_game_objects();
private:
  std::vector<std::unique_ptr<GameObject>> scene_game_objects; 
};
