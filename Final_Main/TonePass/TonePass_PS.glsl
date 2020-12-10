#version 330

//Output variable
layout (location = 0) out vec4 rtFragColor;

//Varying(s) 
in vec2 vTexcoord;

//Uniforms
uniform sampler2D uTex;

// Getting Luminacity color for each pixel
// Referening CookBook By: David Wolff
float Luma (in vec3 color)
{
    return 0.2126 * color.r + 
           0.7152 * color.g + 
           0.0722 * color.b;
}

// Brightening and darkening pixels based on luminocity
// Referening CookBook By: David Wolff
vec4 TonePass(in vec2 fragCoord)
{
	//Getting ScenePass
	vec2 uv = vTexcoord.xy;
	vec4 val = texture(uTex, vTexcoord.xy);
	
	//Getting Constriants for Tone Effect
	return val * clamp(Luma(val.rgb) - 0.5, 0.0, 1.0) *
			(1.0 / (1.0 - 0.5));
}

void main()
{
	//Outputs Tone Effect
	rtFragColor = TonePass(vTexcoord); //texture(uTex, vTexcoord.xy);
}