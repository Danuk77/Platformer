#define GLFW_USE_WIN32
#include <models/gamemanager.hpp>
#include <platformer.hpp>
#include <window.hpp>

int main() {
  GLFWwindow *game_window = create_window();
  game_loop(game_window);

  glfwTerminate();
  return 0;
}
