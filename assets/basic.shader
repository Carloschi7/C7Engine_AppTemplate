#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 col;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 color;

void main()
{
	color = col;
	gl_Position = proj * view * model * vec4(pos, 1.0f);
}

#shader fragment
#version 330 core

in vec3 color;
out vec4 FragColor;

void main()
{
	FragColor = vec4(color, 1.0f);
}