#version 330 core
// vertex data (<vec2 position, vec2 texture_coordinates>)
layout (location = 0) in vec4 vertex_data;

out vec2 texture_coordinates;

uniform mat4 model_matrix;
uniform mat4 projection_matrix;

void main(){
  // Set z coordinates to 0.0 as its 2D
  gl_Position = projection_matrix * model_matrix * vec4(vertex_data.xy, 0.0, 1.0f);
  texture_coordinates = vertex_data.zw;
}
