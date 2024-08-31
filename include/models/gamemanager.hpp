#pragma once
#include "models/scene.hpp"
#include <models/sprite.hpp>
#include <models/shader.hpp>
#include <file_reader.hpp>
#include <unordered_map>
#include <models/shader_program_config.hpp>

class Gamemanager{
public:
  Gamemanager(){};
  static unsigned int current_shader;
  static Scene current_scene;

  static void load_shader(ShaderProgramConfiguration shader_program_configuration);
  static void load_sprite(const char *sprite_path, std::string sprite_name);

  static Shader get_shader(std::string shader_name);
  static Sprite get_sprite(std::string sprite_name);

  static void render_current_scene();
  static void change_scene(Scene new_scene);
  
private:
  static std::unordered_map<std::string, Sprite> loaded_sprites;
  static std::unordered_map<std::string, Shader> loaded_shaders;
};
