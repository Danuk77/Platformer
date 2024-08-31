#pragma once
#include <models/sprite_information.hpp>
#include <stb/stb_image.h>
#include <glad/glad.h>
#include <iostream>

std::string read_shader_file(const char *shader_path);
SpriteInformation read_sprite_image(const char *sprite_path);
void check_sprite_loading_errors(SpriteInformation &sprite_data,
                                 const char *sprite_path);
GLenum identify_format(unsigned int number_of_channels);
