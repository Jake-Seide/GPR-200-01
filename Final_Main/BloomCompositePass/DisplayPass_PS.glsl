#version 330

//Output Variable
layout (location = 0) out vec4 rtFragColor;

//Varying
in vec2 vTexcoord;

//Uniforms
uniform sampler2D uTex_0;
uniform sampler2D uTex_1;

//Creating Composite of Scene and Blur Passes
vec4 ImageComposite()
{
    vec4 val = texture(uTex_1, vTexcoord);
    vec4 sum = texture(uTex_0, vTexcoord);;

    return sum + val;
}

void main()
{
    //Outputs Final Display
    rtFragColor = ImageComposite();
    
}