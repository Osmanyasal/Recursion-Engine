#version 330 core

// Input vertex attributes
in vec3 position;  // Vertex position

// Output to the Fragment Shader
out vec3 fragColor;  // Color to be passed to the fragment shader

void main() {
    // Pass the vertex position to the fragment shader as-is
    gl_Position = vec4(position, 1.0);
    
    // For simplicity, set a fixed color for all vertices
    fragColor = vec3(1.0, 0.5, 0.0); // Orange color
}