#pragma once

static const char* shape_vertex =
R"(
#version 330 core
layout (location = 0) in vec3 vertex;

uniform mat4 projection;
uniform mat4 transform;
void main()
{
	gl_Position = projection * transform * vec4(vertex, 1.0);
}

)";
static const char* texture_vertex =
R"(
#version 330 core
layout (location = 0) in vec3 vertex;

out vec2 TexCoords;

uniform mat4 transform;
uniform mat4 projection;

void main()
{
    TexCoords = vertex.xy;

    gl_Position = projection * transform * vec4(vertex, 1.0f);
}
)";
static const char* text_fragment =
R"(
#version 330 core

in vec2 TexCoords;

uniform sampler2D text;
uniform vec4 textColor;

out vec4 FragColor;
void main() {
    vec4 alphaSampler = vec4(1.0, 1.0, 1.0, texture(text, TexCoords.xy).r);
    FragColor = textColor * alphaSampler;
}
)";
static const char* texture_fragment =
R"(
#version 330 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D sprite;
uniform vec4 spriteColor;

void main()
{
    FragColor = spriteColor * texture(sprite, TexCoords);
}
)";
static const char* rect_fragment =
R"(

#version 330 core
out vec4 FragColor;

uniform vec4 rectColor;

void main()
{
    FragColor = rectColor;
}

)";
