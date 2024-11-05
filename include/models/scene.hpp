#pragma once
#include "models/game_objects/drawable_object.hpp"
#include <models/game_objects/scene_object.hpp>
#include <models/game_objects/player.hpp>
#include <memory>
#include <vector>

class Scene{
public:
  Scene(){};
  void render();
  void add_game_object(std::unique_ptr<DrawableObject> object);
  void add_game_object(std::unique_ptr<SceneObject> object);
  void add_game_object(std::unique_ptr<Player> object);
  int get_number_of_loaded_game_objects();
  std::unique_ptr<Player> player_object;
  std::vector<std::unique_ptr<DrawableObject>> scene_game_objects; 
  std::vector<std::unique_ptr<SceneObject>>  scene_collidable_objects;
};
