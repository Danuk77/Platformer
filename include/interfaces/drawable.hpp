#pragma once
#include <iostream>

class IDrawable{
public:
  IDrawable(){};
  virtual void set_sprite(std::string sprite_name) = 0;
  virtual void set_shader(std::string shader_name) = 0;
  virtual void draw() = 0;
private:
  virtual void set_vertex_data() = 0;
  virtual void initialise_model_matrix() = 0;
};
