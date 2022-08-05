#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;
layout(location = 2) in vec3 tex_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 light_space;

out FS_COMPONENTS
{
	vec3 Pos;
	vec3 Norm;
	vec2 TexCoord;
	vec4 PosInLightSpace;
} comps;

void main()
{
	comps.Pos = vec3(model * vec4(pos, 1.0f));
	comps.Norm = normalize(transpose(inverse(mat3(model))) * normalize(norm));
	comps.TexCoord = tex_coord;
	comps.PosInLightSpace = light_space * vec4(comps.Pos, 1.0f);
}

#shader fragment
#version 330 core

uniform vec3 light_pos;

uniform sampler2D diffuse_texture;
uniform sampler2D depth_texture;

in FS_COMPONENTS
{
	vec3 Pos;
	vec3 Norm;
	vec2 TexCoord;
	vec4 PosInLightSpace;
} comps;

void main()
{
	vec3 light_color = vec3(1.0f);
	vec3 texture_color = texture(diffuse_texture, comps.TexCoord);
	
	//Calculating ambient
	vec3 ambient = 0.05f * light_color;

	//Calculating diffuse
	vec3 CameraToPos = light_pos - comps.Pos;
	float factor = max(0.1f, dot(comps.Norm, normalize(CameraToPos)));
	float attenuationFactor = 0.01f;
	float attenuation = pow(length(CameraToPos), 2) * attenuationFactor;
	vec3 diffuse = (light_color * factor) / attenuation;

	//Calculating shadow
}

