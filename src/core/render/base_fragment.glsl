#version 330 core

// Input from the vertex shader
in vec3 fragColor;  // Color received from the vertex shader

// Output to the screen (pixels)
out vec4 outColor;  // Final color of the pixel

void main() {
    // Set the color of the fragment (pixel) to the one received from the vertex shader
    outColor = vec4(fragColor, 1.0);
}