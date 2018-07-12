#version 330 core
layout(location=0) in vec3 vPos;
layout(location=1) in vec3 vColor;
layout(location=2) in vec2 vTexcorrds;

out vec3 color;
out vec2 texcorrds;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main(){
    gl_Position= projection*view*model* vec4(vPos,1.0);
    color=vec3(vColor);
    texcorrds=vec2(vTexcorrds);
}
