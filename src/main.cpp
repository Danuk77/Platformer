#include "models/game_object.hpp"
#include "models/shader_program_config.hpp"
#define GLFW_USE_WIN32
#include <models/gamemanager.hpp>
#include <platformer.hpp>
#include <window.hpp>

int main() {
  GLFWwindow *game_window = create_window();
  Gamemanager::load_sprite("X:\\Side projects\\Platformer\\sprites\\read_sprites\\00_char_blue.png", "test_sprite");
  ShaderProgramConfiguration config;
  config.vertex_shader_path = "X:\\Side projects\\Platformer\\src\\shaders\\vertex_shader.glsl";
  config.fragment_shader_path = "X:\\Side projects\\Platformer\\src\\shaders\\fragment_shader.glsl";
  config.shader_program_name = "test_shader";
  Gamemanager::load_shader(config);
  GameObject test_object("test_object", glm::vec2(200.0f, 200.0f), glm::vec2(150.0f, 200.0f), 0.0f, "test_sprite", "test_shader");
  GameObject test_object2("test_object2", glm::vec2(300.0f, 300.0f), glm::vec2(150.0f, 200.0f), 0.0f, "test_sprite", "test_shader");
  Gamemanager::current_scene.add_game_object(test_object);  
  Gamemanager::current_scene.add_game_object(test_object2);
  game_loop(game_window);
  glfwTerminate();
  return 0;
}
