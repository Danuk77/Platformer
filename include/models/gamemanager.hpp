#pragma once
#include <models/shader.hpp>
#include <models/sprite.hpp>
#include <unordered_map>
#include <models/shader_program_config.hpp>

class Gamemanager{
public:
  Gamemanager(){};

  static void load_shader(ShaderProgramConfiguration shader_program_configuration);
  static void load_sprite(const char *sprite_path);

  static Shader get_shader(std::string shader_name);
  static Sprite get_sprite();
  
private:
  static std::unordered_map<std::string, Sprite> loaded_sprites;
  static std::unordered_map<std::string, Shader> loaded_shaders;
};
