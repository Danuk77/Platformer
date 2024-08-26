#include <file_reader.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::string read_shader_file(const char *shader_path) {
  std::ifstream shader_file_buffer;

  // Ensure ifstream objects can throw exceptions
  shader_file_buffer.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    shader_file_buffer.open(shader_path);
    std::stringstream shader_file_string_stream;

    shader_file_string_stream << shader_file_buffer.rdbuf();
    shader_file_buffer.close();

    return shader_file_string_stream.str();
  } catch (std::ifstream::failure e) {
    throw(std::runtime_error("ERROR::SHADER::COULD NOT READ SHADER FILE"));
  }
}

SpriteInformation read_sprite_image(const char *sprite_path) {
  SpriteInformation sprite_information;
  stbi_load(sprite_path, &sprite_information.sprite_width,
            &sprite_information.sprite_height,
            &sprite_information.number_of_channels, 0);

  check_sprite_loading_errors(sprite_information, sprite_path);
  sprite_information.sprite_colour_format =
      identify_format(sprite_information.number_of_channels);

  return sprite_information;
}

void check_sprite_loading_errors(SpriteInformation &loaded_sprite,
                                 const char *sprite_path) {
  // Check if the sprite image was read properly
  if (!loaded_sprite.sprite_data) {
    stbi_image_free(loaded_sprite.sprite_data);
    throw std::runtime_error("Failed to load sprite: " +
                             std::string(sprite_path));
  }
}

GLenum identify_format(unsigned int number_of_channels) {
  switch (number_of_channels) {
  case 1:
    return GL_RED;
  case 3:
    return GL_RGB;
  case 4:
    return GL_RGBA;
  default:
    throw std::runtime_error("Unsupported texture type");
  }
}
