#pragma once
#include "interfaces/drawable.hpp"
#include "models/game_objects/game_object.hpp"

class DrawableObject: public IDrawable, public GameObject{
public:
  DrawableObject(std::string object_name, Transform transform, std::string shader_name, std::string sprite_name);
  void set_sprite(std::string sprite_name) override;
  void set_shader(std::string shader_name) override;
  void draw() override;
  void render() override;
protected:
  Sprite object_sprite;
  Shader shader_program;

  static unsigned int vertex_array_object, vertex_buffer_object;
  glm::mat4 model_matrix;
  static glm::mat4 projection_matrix;

  void set_vertex_data() override;
  void initialise_model_matrix() override;
};
