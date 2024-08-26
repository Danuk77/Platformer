#include "models/gamemanager.hpp"
#include <platformer.hpp>

void game_loop(GLFWwindow *game_window){
  while(!glfwWindowShouldClose(game_window)){
    clear_screen();  
    glfwSwapBuffers(game_window);
    Gamemanager::render_current_scene();
    glfwPollEvents();
  }
}

void clear_screen(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
