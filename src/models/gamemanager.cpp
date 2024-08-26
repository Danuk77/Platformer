#include <models/shader.hpp>
#include <models/gamemanager.hpp>
#include <stdexcept>
#include <unordered_map>

std::unordered_map<std::string, Sprite> Gamemanager::loaded_sprites;
std::unordered_map<std::string, Shader> Gamemanager::loaded_shaders;

void Gamemanager::load_shader(
    ShaderProgramConfiguration shader_program_configuration) {
  const char *vertex_shader_path = shader_program_configuration.vertex_shader_path;
  const char *fragment_shader_path = shader_program_configuration.fragment_shader_path;

  std::string vertex_shader_code = read_shader_file(vertex_shader_path);
  std::string fragment_shader_code = read_shader_file(fragment_shader_path);

  Shader shader(vertex_shader_code.c_str(), fragment_shader_code.c_str());
  Gamemanager::loaded_shaders[shader_program_configuration.shader_program_name] = shader;
}

Shader Gamemanager::get_shader(std::string shader_name) {
  // Check if a shader with the given name exists
  if (Gamemanager::loaded_shaders.find(shader_name) ==
      Gamemanager::loaded_shaders.end()) {
    throw std::runtime_error("GAMEMANAGER::Unable to fetch shader " +
                             shader_name + " ensure the\
    shader has been loaded prior to use");
  }

  Shader shader = loaded_shaders[shader_name];
  return shader;
}
    
void Gamemanager::load_sprite(const char *sprite_path, std::string sprite_name){
  SpriteInformation sprite_data = read_sprite_image(sprite_path);
  Sprite sprite(sprite_data);
  Gamemanager::loaded_sprites[sprite_name] = sprite;
}

Sprite Gamemanager::get_sprite(std::string sprite_name){
  // Check if a sprite with the given name exists
  if(Gamemanager::loaded_sprites.find(sprite_name) == Gamemanager::loaded_sprites.end()){
    throw std::runtime_error("GAMEMANAGER::Unable to fetch sprite " +
                             sprite_name + " ensure the\
    sprite has been loaded prior to use");
  }

  Sprite sprite = loaded_sprites[sprite_name];
  return sprite;
}
