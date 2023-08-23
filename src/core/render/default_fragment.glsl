#version 330 core

uniform sampler2D u_ourTexture;
uniform int u_texture_bound;

// Input from the vertex shader
in vec3 fragColor;  // Color received from the vertex shader
in vec3 pos;
in vec2 tex_coord;
// Output to the screen (pixels)
out vec4 outColor;  // Final color of the pixel
 
void main() {
    if(u_texture_bound == 1)
        outColor = texture(u_ourTexture,tex_coord); // vec4(fragColor,1.0f); //vec4(pos.zzz * -1  , 1.0);
    else outColor = vec4(fragColor,1.0f);
}