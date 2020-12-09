#version 330

layout (location = 0) out vec4 rtFragColor;

in vec2 vTexcoord;

uniform sampler2D uTex;

float Luma (in vec3 color)
{
    return 0.2126 * color.r + 
           0.7152 * color.g + 
           0.0722 * color.b;
}

vec4 TonePass(in vec2 fragCoord)
{
	vec2 uv = vTexcoord.xy;
	vec4 val = texture(uTex, vTexcoord.xy);
	
	return val * clamp(Luma(val.rgb) - 0.5, 0.0, 1.0) *
			(1.0 / (1.0 - 0.5));
}

void main()
{
	rtFragColor = TonePass(vTexcoord); //texture(uTex, vTexcoord.xy);
}