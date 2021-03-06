#version 330

//declare output
layout (location = 0) out vec4 rtFragColor;

//Uniforms
uniform sampler2D uTex;

//Varying(ps)
in vec4 vPosition;
in vec2 vTexcoord;

// Reference Link: http://rastergrid.com/blog/2010/09/efficient-gaussian-blur-with-linear-sampling/
vec4 BlurrPass()
{
    float offset[5] = float[](0.0, 1.0, 2.0, 3.0, 4.0);
    float weight[5] = float[](0.29, 0.25, 0.2, 0.15, 0.1);

	//Getiing Tone Pass
    rtFragColor = texture(uTex, vTexcoord) * weight[0];
    
	// Optimazation for for-loop
    // Blurring by the offset on the x and y axis
    rtFragColor += texture(uTex, vTexcoord + vec2(0.0, offset[0])) * weight[0];
    rtFragColor += texture(uTex,  vTexcoord - vec2(0.0, offset[0])) * weight[0];

    rtFragColor += texture(uTex, vTexcoord + vec2(0.0, offset[1])) * weight[1];
    rtFragColor += texture(uTex,  vTexcoord - vec2(0.0, offset[1])) * weight[1];

    rtFragColor += texture(uTex, vTexcoord + vec2(0.0, offset[2])) * weight[2];
    rtFragColor += texture(uTex,  vTexcoord - vec2(0.0, offset[2])) * weight[2];

    rtFragColor += texture(uTex, vTexcoord + vec2(0.0, offset[3])) * weight[3];
    rtFragColor += texture(uTex,  vTexcoord - vec2(0.0, offset[3])) * weight[3];

    rtFragColor += texture(uTex, vTexcoord + vec2(0.0, offset[4])) * weight[4];
    rtFragColor += texture(uTex,  vTexcoord - vec2(0.0, offset[4])) * weight[4];

    return rtFragColor;
}

// mainImage: process the current pixel (exactly one call per fragment)
void main()
{
    //Outputs Blur Effect
    rtFragColor = BlurrPass();
}