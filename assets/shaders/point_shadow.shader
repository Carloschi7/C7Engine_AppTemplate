#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 norm;
layout(location = 2) in vec2 tex_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
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
	gl_Position = proj * view * vec4(comps.Pos, 1.0f);
}

#shader fragment
#version 330 core

uniform vec3 light_pos;
uniform vec3 camera_pos;

uniform sampler2D diffuse_texture;
uniform sampler2D depth_texture;

in FS_COMPONENTS
{
	vec3 Pos;
	vec3 Norm;
	vec2 TexCoord;
	vec4 PosInLightSpace;
} comps;

out vec4 FragColor;

void main()
{
	vec3 LightColor = vec3(1.0f);
	vec3 TextureColor = texture(diffuse_texture, comps.TexCoord).xyz;
	
	//Calculating ambient
	vec3 Ambient = 0.05f * LightColor;

	//Calculating diffuse
	vec3 FragmentToLight = light_pos - comps.Pos;

	//Calculating if the fragment is exposed to the light
	float orientation = dot(comps.Norm, normalize(FragmentToLight));
	if (orientation < 0.0f)
	{
		FragColor = vec4(Ambient * TextureColor, 1.0f);
		return;
	}

	float factor = max(0.1f, orientation);
	float attenuationFactor = 0.01f;
	float attenuation = pow(length(FragmentToLight), 2) * attenuationFactor;
	vec3 Diffuse = (LightColor * factor) / attenuation;

	//Calculating specular
	vec3 FragmentToCamera = -normalize(camera_pos - comps.Pos);
	vec3 Reflected = reflect(FragmentToCamera, comps.Norm);
	float spec = pow(max(dot(Reflected, normalize(FragmentToLight)), 0.0f), 100);
	vec3 Specular = LightColor * spec;

	//Calculating 3D shadow
	vec3 ClampedPos = comps.PosInLightSpace.xyz / comps.PosInLightSpace.w;
	ClampedPos = (ClampedPos + vec3(1.0f)) * 0.5f;

	if (ClampedPos.x < 0.0f || ClampedPos.y < 0.0f || ClampedPos.x > 1.0f || ClampedPos.y > 1.0f)
	{
		FragColor = vec4((Ambient + Diffuse + Specular) * TextureColor, 1.0f);
		return;
	}

	float current_z = ClampedPos.z - 0.01f;
	float nearest_z = texture(depth_texture, ClampedPos.xy).r;
	float shadow = (current_z > nearest_z) ? 0.0f : 1.0f;

	FragColor = vec4((Ambient + shadow * (Diffuse + Specular)) * TextureColor, 1.0f);
}

