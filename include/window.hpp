#define GLFW_USE_WIN32

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <assimp/ObjMaterial.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
GLFWwindow *create_window();

