#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 viewproj;

void main() {
    gl_Position = viewproj * model * vec4(pos, 1.0);
    TexCoord = texCoord;
}