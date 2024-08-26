#include "models/game_object.hpp"
#include "models/shader_program_config.hpp"
#define GLFW_USE_WIN32
#include <models/gamemanager.hpp>
#include <platformer.hpp>
#include <window.hpp>

int main() {
  GLFWwindow *game_window = create_window();
  Gamemanager::load_sprite("X:\\Side projects\\Platformer\\sprites\\read_sprites\\01_Idle-Sheet.png", "test_sprite");
  ShaderProgramConfiguration config;
  config.vertex_shader_path = "X:\\Side projects\\Platformer\\src\\shaders\\vertex_shader.glsl";
  config.fragment_shader_path = "X:\\Side projects\\Platformer\\src\\shaders\\fragment_shader.glsl";
  config.shader_program_name = "test_shader";
  Gamemanager::load_shader(config);
  GameObject test_object("test_object", glm::vec2(50.0f, 50.0f), glm::vec2(10.0f, 10.0f), 0.0f, "test_sprite", "test_shader");
  Gamemanager::current_scene.add_game_object(test_object);  
  game_loop(game_window);
  glfwTerminate();
  return 0;
}
