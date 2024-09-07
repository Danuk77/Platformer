#include "models/clock.hpp"
#include "models/gamemanager.hpp"
#include "models/shader.hpp"
#include <platformer.hpp>

void game_loop(GLFWwindow *game_window){
  while(!glfwWindowShouldClose(game_window)){
    Clock::update_time();
    Gamemanager::render_current_scene();
    glfwSwapBuffers(game_window);
    clear_screen();
    glfwPollEvents();
  }
}

void clear_screen(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
