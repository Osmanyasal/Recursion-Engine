#version 330 core

// Input vertex attributes
layout (location = 0) in vec3 position;  // Vertex position
layout (location = 1) in vec4 color; // the color variable has attribute position 1
layout (location = 2) in vec2 texture; // the color variable has attribute position 1
layout (location = 3) in vec3 normals; // the color variable has attribute position 1
  
uniform mat4 u_view_projection;
uniform mat4 u_model;

// Output to the Fragment Shader
out vec4 fragColor;  // Color to be passed to the fragment shader
out vec3 pos;
out vec2 tex_coord;

void main() {
    // Pass the vertex position to the fragment shader as-is
    gl_Position =  u_view_projection * u_model * vec4(position, 1.0);
    fragColor = color; 
    tex_coord = texture;
}