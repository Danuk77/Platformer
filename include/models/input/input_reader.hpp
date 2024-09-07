#pragma once
#include "interfaces/movable.hpp"
#include <vector>

class InputReader{
public:
  InputReader(){};
  std::vector<Input> read_user_input();
private:
};
