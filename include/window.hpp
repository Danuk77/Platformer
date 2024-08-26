#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
GLFWwindow *create_window();
void configure_opengl_version();

