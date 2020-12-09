#version 330

layout(location = 0) out vec4 rtFragColor;

uniform sampler2D uTex;

in vec2 vTexcoord;
in float noise;

float random( vec3 scale, float seed ){
  return fract( sin( dot( gl_FragCoord.xyz + seed, scale ) ) * 43758.5453 + seed ) ;
}

void main()
{
	float r = 0.01 * random(vec3(12.9898, 78.233, 151.7182), 0.0);

	vec2 tPos = vec2(0.0, 1.3 * noise + r);
	vec4 color = texture(uTex, tPos);
	
	//vec3 color = vec3(vTexcoord * (1.0 - 2.0 * noise), 0.0);
	//rtFragColor = vec4(color.rgb, 1.0);
	rtFragColor = texture(uTex, vTexcoord);
}
