#version 330 core

// Input vertex attributes
layout (location = 0) in vec3 position;  // Vertex position
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
  

// Output to the Fragment Shader
out vec3 fragColor;  // Color to be passed to the fragment shader
out vec3 pos;

void main() {
    // Pass the vertex position to the fragment shader as-is
    gl_Position = vec4(position, 1.0);
    pos = position;
    // For simplicity, set a fixed color for all vertices
    fragColor = aColor; //vec3(1.0, 0.5, 0.0); // Orange color
}