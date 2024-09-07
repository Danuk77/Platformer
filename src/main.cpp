#include "models/game_objects/drawable_object.hpp"
#include "models/game_objects/transform.hpp"
#include "models/shader.hpp"
#include "models/shader_program_config.hpp"
#include "models/game_objects/player.hpp"
#include <memory>
#include <utility>
#define GLFW_USE_WIN32
#include <models/gamemanager.hpp>
#include <platformer.hpp>

void enable_transparent_rendering();
void generate_ground();

int main() {
  GLFWwindow *game_window = Gamemanager::create_window();
  enable_transparent_rendering();

  Gamemanager::load_sprite("X:\\Side projects\\Platformer\\sprites\\read_sprites\\01_char_blue.png", "test_sprite");
  Gamemanager::load_sprite("X:\\Side projects\\Platformer\\sprites\\oak_woods_v1.0\\background\\background_layer_1.png", "background");
  Gamemanager::load_sprite("X:\\Side projects\\Platformer\\sprites\\read_sprites\\brackeys\\08_world_tileset.png", "test_ground");

  ShaderProgramConfiguration config;
  config.vertex_shader_path = "X:\\Side projects\\Platformer\\src\\shaders\\vertex_shader.glsl";
  config.fragment_shader_path = "X:\\Side projects\\Platformer\\src\\shaders\\fragment_shader.glsl";
  config.shader_program_name = "test_shader";
  Gamemanager::load_shader(config);

  // TODO: Wrap these logics around in a class, etc..
  Transform background_transform(glm::vec2(.0f, .0f), glm::vec2(800.0f, 600.0f), 0.0f);
  std::unique_ptr<DrawableObject> test_background_ptr = std::make_unique<DrawableObject>("test_background", background_transform, "test_shader", "background");
  Gamemanager::current_scene.add_game_object(std::move(test_background_ptr));

  Transform player_transform(glm::vec2(200.0f, 200.0f), glm::vec2(50.0f, 75.0f), 0.0f);
  std::unique_ptr<Player> player = std::make_unique<Player>("test_object", player_transform, "test_shader", "test_sprite");
  Gamemanager::current_scene.add_game_object(std::move(player));

  generate_ground();

  game_loop(game_window);
  glfwTerminate();
  return 0;
}

// Enables rendering transparent textures
void enable_transparent_rendering(){
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void generate_ground(){
  int ground_object_size = 16;
  int number_of_ground_objects = 800 / ground_object_size;
  int number_of_layers = 100 / ground_object_size;

  for(int j = 0; j < number_of_layers + 1; j++){
      float y_pos = 500 + (j * ground_object_size);
      for(int i = 0; i < number_of_ground_objects; i++){
        float x_pos = i * ground_object_size;
        Transform test_object_transform(glm::vec2(x_pos, y_pos), glm::vec2(16.0f, 16.0f), 0.0f);
        std::unique_ptr<DrawableObject> test_object = std::make_unique<DrawableObject>("test_ground", test_object_transform, "test_shader", "test_ground");
        Gamemanager::current_scene.add_game_object(std::move(test_object));
      }
  }
}
