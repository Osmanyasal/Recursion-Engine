#version 330 core

// Input vertex attributes
layout (location = 0) in vec3 position;  // Vertex position
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec2 aTexture; // the color variable has attribute position 1
  
uniform mat4 mvp;

// Output to the Fragment Shader
out vec3 fragColor;  // Color to be passed to the fragment shader
out vec3 pos;
out vec2 tex_coord;

void main() {
    // Pass the vertex position to the fragment shader as-is
    gl_Position =  mvp * vec4(position, 1.0);
    pos = position;
    // For simplicity, set a fixed color for all vertices
    fragColor = aColor; //vec3(1.0, 0.5, 0.0); // Orange color
    tex_coord = aTexture;
}