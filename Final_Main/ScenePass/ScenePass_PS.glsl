#version 330

//Output variable
layout(location = 0) out vec4 rtFragColor;

//Varying
in float vTime;
in float noise;
in vec2 vTexcoord;
in vec4 vNormal;
in vec4 vPosition;

//Uniforms
uniform sampler2D uTex;

//Light struct
struct lights
{
	vec4 lightPos;
	vec4 diffuseColor;
	vec4 specColor;
};

// Inializing the lights with desired location ands colors
lights LightInit(lights initLight, vec4 lightPos, 
						vec4 diffuseColor, vec4 specColor)
{
	initLight.lightPos = lightPos;
	initLight.diffuseColor = diffuseColor;
	initLight.specColor = specColor;

	return initLight;
}

vec4 PhongReflection(lights currentLight)
{
	// Normalizes the normal attribute
	vec4 normal = normalize(vNormal);
	
	currentLight.lightPos = vec4(vec3(cos((vTime / 2.0) * 10.0), sin((vTime / 2.0) * 10.0), 0.05), 0.5);
    currentLight.lightPos.xy = currentLight.lightPos.xy * currentLight.lightPos.xy * 0.3 + 0.5; //vec2(sin(vTime * 0.5), sin (vTime * 0.5));
	
	// Gets light direciton by normalizing light position and fragment postion
	vec4 lightDir = normalize(currentLight.lightPos - vPosition);
	
	// Getting Lambert diffusion
	float lambertian = max(((lightDir.x * normal.x) +
							(lightDir.y * normal.y) +
							(lightDir.z * normal.z) +
							(lightDir.w * normal.w)), 0.0);
	float specular = 0.0;
	
	// Setting lambert
	if(lambertian > 0.0)
	{
		// Refleciton of light on the "surface" of the sphere
		vec4 reflectDir = reflect(lightDir, normal);

		// Getting view direciton from the normalazed fragment position
		vec4 viewDir = normalize(vPosition);
		
		// Getting the specular angles off of the sphere
		float specAngle = max(((reflectDir.x * viewDir.x) +
							   (reflectDir.y * viewDir.y) +
							   (reflectDir.z * viewDir.z) +
							   (reflectDir.w * viewDir.w)), 0.0);
							   
		// Multipling angle 4 times instead of power of 4
		specular = specAngle * specAngle * specAngle * specAngle; //pow(specAngle, 4.0);
	}
		
	// returning final Phong Reflection
	return vec4(lambertian * currentLight.diffuseColor + specular * currentLight. specColor);
}

void main()
{
	//Init lights
	lights light;
	light = LightInit(light, vec4(1.0, 1.0, 1.0, -1.0), vec4(1.0, 0.0, 0.0, 1.0), vec4(1.0, 1.0, 1.0, 1.0));
	
	//Output to ScenePassRT (sphere + phong shading)
	rtFragColor = texture(uTex, vTexcoord) + PhongReflection(light); //vec4(color.rgb, 1.0) + PhongReflection(light);
	
}