#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 Pos;
out vec3 Norm;

void main()
{
	Pos = pos;
	Norm = normalize(norm);
	gl_Position = proj * view * model * vec4(pos, 1.0f);
}

#shader fragment
#version 330 core

uniform samplerCube skybox;
uniform vec3 camera_pos;

in vec3 Pos;
in vec3 Norm;

out vec4 FragColor;

void main()
{
	vec3 PosToCamera = normalize(camera_pos - Pos);
	vec3 Reflected = reflect(PosToCamera, Norm);
	FragColor = texture(skybox, Reflected);
}