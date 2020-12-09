#version 330

layout (location = 0) out vec4 rtFragColor;

in vec2 vTexcoord;

uniform sampler2D uTex_0;
uniform sampler2D uTex_1;

vec4 ImageComposite()
{
    vec4 val = texture(uTex_1, vTexcoord);
    vec4 sum = texture(uTex_0, vTexcoord);;

    return sum + val;//mix(val, sum, 0.4);
}

void main()
{
    //vec2 uv = vTexcoord;
    //vec4 col = texture(uTex, uv);
    rtFragColor = ImageComposite();
    //rtFragColor = vec4(1.0, 1.0, 0.0, 1.0);
}