#pragma once
#include <glm/glm.hpp>

struct Transform {
  glm::vec2 position;
  glm::vec2 size;
  float rotation;

  Transform(glm::vec2 position, glm::vec2 size, float rotation)
      : position(position), size(size), rotation(rotation) {}
};
