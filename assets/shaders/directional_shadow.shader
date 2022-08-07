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

uniform vec3 light_direction;

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
	vec3 TextureColor = texture(diffuse_texture, comps.TexCoord).rgb;

	vec3 Ambient = LightColor * 0.05f;

	//Calculating if the fragment is exposed to the light
	float orientation = dot(comps.Norm, normalize(-light_direction));
	if (orientation < 0.0f)
	{
		FragColor = vec4(Ambient * TextureColor, 1.0f);
		return;
	}

	//Calculate lighting
	float factor = max(0.1f, orientation);
	vec3 Diffuse = (LightColor * factor);

	//Shadow calculation
	vec4 LightSpacePos = comps.PosInLightSpace;
	vec3 Clamped = LightSpacePos.xyz / LightSpacePos.w;
	Clamped = (Clamped + vec3(1.0f)) / 2.0f;

	//If the fragment is outside the rendered scope of the shadow calcultation, we just forward
	//the plain ambient and diffuse
	if (Clamped.x < 0.0f || Clamped.x > 1.0f || Clamped.y < 0.0f || Clamped.y > 1.0f)
	{
		FragColor = vec4((Ambient + Diffuse) * TextureColor, 1.0f);
		return;
	}

	float nearest_z = texture(depth_texture, Clamped.xy).r;
	float z_bias = 0.001f;
	float current_z = Clamped.z - z_bias;
	float shadow = (nearest_z < current_z) ? 0.0f : 1.0f;

	FragColor = vec4((Ambient + shadow * Diffuse) * TextureColor, 1.0f);
}