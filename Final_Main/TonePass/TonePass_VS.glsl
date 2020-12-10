#version 330

//Atributes
layout (location = 0) in vec4 aPosition;
layout (location = 2) in vec2 aTexcoord;

//Uniforms
uniform mat4 uModelMat, uViewMat, uProjMat, uViewProjMat;

//Varyings
out vec2 vTexcoord;

void main()
{
	//Setting Position Attributes
	gl_Position = aPosition;
	
	//Set Texture Varyings
	vTexcoord = aTexcoord;
	vTexcoord = aPosition.xy * 0.5 + 0.5;
}