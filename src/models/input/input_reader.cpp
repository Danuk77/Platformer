#include "models/input/input_reader.hpp"
#include "models/gamemanager.hpp"


std::vector<Input> InputReader::read_user_input(){
  std::vector<Input> current_frame_inputs;
  GLFWwindow *window = Gamemanager::current_window;

  if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
    current_frame_inputs.push_back(LEFT);
  }

  if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
    current_frame_inputs.push_back(RIGHT);
  }

  if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
    current_frame_inputs.push_back(UP);
  }

  if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
    current_frame_inputs.push_back(DOWN);
  }
  return current_frame_inputs;
}
