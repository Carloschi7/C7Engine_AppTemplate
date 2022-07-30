#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;

uniform mat4 space;
uniform mat4 model;

void main()
{
	gl_Position = space * model * vec4(pos, 1.0f);
}

#shader fragment
#version 330 core

void main()
{
	//gl_FragDepth = gl_FragCoord.z;
}