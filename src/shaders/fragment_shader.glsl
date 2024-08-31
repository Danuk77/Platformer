#version 330 core
in vec2 texture_coordinates;
out vec4 output_color;

uniform sampler2D sprite;
// TODO: Not sure this is for so might get rid of
uniform vec3 sprite_color;

void main(){
  output_color = texture(sprite, texture_coordinates);
  // output_color = vec4(sprite_color, 1.0f) * texture(sprite, texture_coordinates);
}
