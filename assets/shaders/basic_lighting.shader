#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;
layout(location = 2) in vec2 tex_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 Pos;
out vec3 Norm;
out vec2 TexCoord;

void main()
{
	Pos = vec3(model * vec4(pos, 1.0f));
	Norm = transpose(inverse(mat3(model))) * normalize(norm);
	TexCoord = tex_coord;
	gl_Position = proj * view * vec4(Pos, 1.0f);
}

#shader fragment
#version 330 core

uniform sampler2D texture1;
uniform vec3 light_pos;

in vec3 Pos;
in vec3 Norm;
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
	vec3 PosToLight = light_pos - Pos;
	float brightnessMultiplier = 0.01f;
	float brightness = pow(length(PosToLight), 2) * brightnessMultiplier;
	float diffuse = max(0.2f, dot(Norm, normalize(PosToLight)));
	FragColor = (texture(texture1, TexCoord) * diffuse) / brightness;
}