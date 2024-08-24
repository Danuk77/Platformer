#define GLFW_USE_WIN32
#include <iostream>
#include <window.hpp>
#include <platformer.hpp>

int main(){
  GLFWwindow *game_window = create_window();
  game_loop(game_window);

  glfwTerminate();
  return 0;
}
