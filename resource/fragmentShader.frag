#version 330 core
in vec3 color;
in vec2 texcorrds;

uniform sampler2D texture_diffuse1;

out vec4 FragColor;
void main(){
    FragColor = texture(texture_diffuse1,texcorrds);
}
