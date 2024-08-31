#pragma once
#include <models/shader.hpp>
#include <models/sprite.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GameObject{
public:
  GameObject(std::string object_name, glm::vec2 position, glm::vec2 size, float rotation, std::string sprite, std::string shader);
  void render();
private:
  std::string object_name;
  static glm::mat4 projection_matrix;
  glm::vec2 position;
  glm::vec2 size;
  float rotation;
  glm::mat4 model_matrix;
  Sprite object_sprite;
  Shader shader_program;
  static unsigned int vertex_array_object, vertex_buffer_object;

  void set_sprite(std::string sprite_name);
  void set_shader(std::string shader_name);
  void set_vertex_data();
  void initialise_model_matrix();
};
