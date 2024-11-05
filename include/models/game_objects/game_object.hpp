#pragma once
#include <models/shader.hpp>
#include <models/sprite.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "models/game_objects/transform.hpp"

class GameObject{
public:
  GameObject(std::string object_name, Transform transform);
  virtual void render() = 0;
  Transform transform;
protected:
  std::string object_name;
};
