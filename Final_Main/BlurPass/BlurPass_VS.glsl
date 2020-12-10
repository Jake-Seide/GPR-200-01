#version 330

//MAIN DUTY: READ ATTRIBUTES
//e.g. 3D pos
//e.g. surface normal
//e.g. uv: texture coord

//Attributes
layout (location = 0) in vec4 aPosition;
layout (location = 2) in vec2 aTexcoord;

//Varying(vs)
out vec4 vPosition;
out vec2 vTexcoord;

void main()
{
	//Setting Position Attributes
	gl_Position = aPosition;
	
	//Set Texture Varyings
	vTexcoord = aTexcoord;
	vTexcoord = aPosition.xy * 0.5 + 0.5;
}