#include "GLFW/glfw3.h"
#include <platformer.hpp>

void game_loop(GLFWwindow *game_window){
  while(!glfwWindowShouldClose(game_window)){
    clear_screen();  
    glfwSwapBuffers(game_window);
    glfwPollEvents();
  }
}

void clear_screen(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
