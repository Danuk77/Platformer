#pragma once
#include <iostream>
#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

enum shader_type{
  VERTEX_SHADER,
  FRAGMENT_SHADER
};

class Shader{
public:
  Shader(){};
  Shader(const char *vertex_shader_code, const char *fragment_shader_code);
private:
  unsigned int shader_program_id; 
  unsigned int compile_shader(const char *&shader_code, shader_type shader_type);
  void check_shader_compile_errors(unsigned int shader);
  void create_program(unsigned int loaded_vertex_shader, unsigned int loaded_fragment_shader);
  void check_shader_linking_errors();
};
