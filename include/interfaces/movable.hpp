#pragma once
#include "models/input/input.hpp"
#include <glm/glm.hpp>

class IMovable{
public:
  IMovable(){};
  virtual void move(Input direction) = 0;
};
