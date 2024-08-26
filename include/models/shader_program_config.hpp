#pragma once
#include <iostream>

struct ShaderProgramConfiguration{
  std::string shader_program_name;
  const char *vertex_shader_path;
  const char *fragment_shader_path;
};
