#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 nor;
layout(location = 2) in vec2 tex;

void main()
{
	gl_Position = vec4(pos, 1.0f);
}