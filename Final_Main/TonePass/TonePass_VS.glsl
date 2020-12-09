#version 330

layout (location = 0) in vec4 aPosition;
layout (location = 2) in vec2 aTexcoord;

//Uniforms
uniform mat4 uModelMat, uViewMat, uProjMat, uViewProjMat;

out vec2 vTexcoord;

void main()
{
	gl_Position = aPosition;

	//mat4 modelViewProjMat = uProjMat * uViewMat * uModelMat;
	//gl_Position = modelViewProjMat * aPosition;
	vTexcoord = aTexcoord;
	vTexcoord = aPosition.xy * 0.5 + 0.5;

	//mat4 modelViewProjMat = uProjMat * uViewMat * uModelMat;
	//gl_Position = modelViewProjMat * aPosition;
	//vTexcoord = aTexcoord;
	//vTexcoord = TonePass(vTexcoord.xy);
}