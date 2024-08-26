#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "models/gamemanager.hpp"
#include "models/shader.hpp"
#include "models/sprite_information.hpp"
#include <models/game_object.hpp>
#include "glad/glad.h"

unsigned int GameObject::vertex_array_object = 0;
unsigned int GameObject::vertex_buffer_object = 0;
glm::mat4 GameObject::projection_matrix = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

GameObject::GameObject(std::string object_name, glm::vec2 position, glm::vec2 size, float rotation, std::string sprite_name, std::string shader_name)
    : object_name(object_name), position(position), rotation(rotation), size(size){
  set_sprite(sprite_name);
  set_shader(shader_name);
  set_vertex_data();
  initialise_model_matrix(); 
}

void GameObject::set_sprite(std::string sprite_name){
  object_sprite = Gamemanager::get_sprite(sprite_name);
}

void GameObject::set_shader(std::string shader_name){
  shader_program = Gamemanager::get_shader(shader_name);
}

void GameObject::set_vertex_data(){
  // Check if the vertex array object and vertex buffer objects
  // have already been generated. We only need to do this once.
  // This is because all our 2D elements will be using the same 
  // vertex_buffer_object and vertex_array_object
  // TODO: this may change
  if(GameObject::vertex_array_object == 0){
    float vertices[] = { 
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 
    
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &GameObject::vertex_array_object);
    glGenBuffers(1, &GameObject::vertex_buffer_object);

    glBindBuffer(GL_ARRAY_BUFFER, GameObject::vertex_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(GameObject::vertex_array_object);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }
}

void GameObject::initialise_model_matrix(){
  model_matrix = glm::mat4(1.0f);
  model_matrix = glm::translate(model_matrix, glm::vec3(position, 0.0f));

  // Rotations revolve around the (0,0) point of the model (which is the top left)
  // We need to rotate it around the model's center, therefore move it half its size to
  // the left, rotate and move back
  model_matrix = glm::translate(model_matrix, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
  model_matrix = glm::rotate(model_matrix, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix = glm::translate(model_matrix, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

  model_matrix = glm::scale(model_matrix, glm::vec3(size, 1.0f));
}

void GameObject::render(){
  //TODO: Temporary value (for testing), maybe move into header as a permanent variable
  glm::vec3 sprite_color = glm::vec3(1.0f, 0.0f, 0.0f);

  shader_program.use();
  shader_program.set_matrix_4("model_matrix", model_matrix);
  shader_program.set_vector_3_float("sprite_color", sprite_color);
  shader_program.set_matrix_4("projection_matrix", GameObject::projection_matrix);

  glActiveTexture(GL_TEXTURE0);
  object_sprite.bind();
  
  // Binding the vertex array object automatically binds the vertex buffer object
  glBindVertexArray(GameObject::vertex_array_object);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
}
