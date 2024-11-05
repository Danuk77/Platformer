#include "models/scene.hpp"
#include <models/shader.hpp>
#include <models/gamemanager.hpp>
#include <stdexcept>
#include <unordered_map>

std::unordered_map<std::string, Sprite> Gamemanager::loaded_sprites;
std::unordered_map<std::string, Shader> Gamemanager::loaded_shaders;
unsigned int Gamemanager::current_shader = 0;
Scene Gamemanager::current_scene = Scene();
GLFWwindow* Gamemanager::current_window;

// Initialises GLFW and GLAD.
GLFWwindow* Gamemanager::create_window()
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialise GLFW" << std::endl;
        return nullptr;
    }

    configure_opengl_version();

    GLFWwindow *window = glfwCreateWindow(800, 600, "Platformer", nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Couldn't create a GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    // Make this windows the current context
    glfwMakeContextCurrent(window);

    // Initialise GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

    // Set the viewport of the opengl context (specifies how much of the window we will take)
    glViewport(0, 0, 800, 600);

    // Register the callback function 'freambuffer_size_callback' to handle window resizing
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Gamemanager::current_window = window;
    return window;
}

void Gamemanager::configure_opengl_version(){
  // Specify the OpenGL versions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

// Callback function to handle the window resizing.
void Gamemanager::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Gamemanager::load_shader(
    ShaderProgramConfiguration shader_program_configuration) {
  const char *vertex_shader_path = shader_program_configuration.vertex_shader_path;
  const char *fragment_shader_path = shader_program_configuration.fragment_shader_path;

  std::string vertex_shader_code = read_shader_file(vertex_shader_path);
  std::string fragment_shader_code = read_shader_file(fragment_shader_path);

  Shader shader(vertex_shader_code.c_str(), fragment_shader_code.c_str());
  Gamemanager::loaded_shaders[shader_program_configuration.shader_program_name] = shader;
}

Shader Gamemanager::get_shader(std::string shader_name) {
  // Check if a shader with the given name exists
  if (Gamemanager::loaded_shaders.find(shader_name) ==
      Gamemanager::loaded_shaders.end()) {
    throw std::runtime_error("GAMEMANAGER::Unable to fetch shader " +
                             shader_name + " ensure the\
    shader has been loaded prior to use");
  }

  Shader shader = loaded_shaders[shader_name];
  return shader;
}
    
void Gamemanager::load_sprite(const char *sprite_path, std::string sprite_name){
  SpriteInformation sprite_data = read_sprite_image(sprite_path);
  Sprite sprite(sprite_data);
  Gamemanager::loaded_sprites[sprite_name] = sprite;
}

Sprite Gamemanager::get_sprite(std::string sprite_name){
  // Check if a sprite with the given name exists
  if(Gamemanager::loaded_sprites.find(sprite_name) == Gamemanager::loaded_sprites.end()){
    throw std::runtime_error("GAMEMANAGER::Unable to fetch sprite " +
                             sprite_name + " ensure the\
    sprite has been loaded prior to use");
  }

  Sprite sprite = loaded_sprites[sprite_name];
  return sprite;
}

void Gamemanager::render_current_scene(){
  current_scene.render();
}

void Gamemanager::change_scene(Scene new_scene){
  //TODO: Implement
}
