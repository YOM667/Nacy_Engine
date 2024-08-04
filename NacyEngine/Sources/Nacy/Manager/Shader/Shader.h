#pragma once

#include "Nacy/Core/Core.h"

namespace Shaders {
    static const char *shape_vertex =
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
    static const char *texture_vertex =
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
    static const char *text_fragment =
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
    static const char *texture_fragment =
            R"(
    #version 330 core
    
    in vec2 TexCoords;
    out vec4 FragColor;
    
    uniform sampler2D sprite;
    uniform vec4 spriteColor;
    uniform bool horizontal = false;
    uniform bool enableBlur = false;
    
    uniform float weight[5] = float[] (0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);
    
    vec3 blur()
    {
        vec2 tex_offset = 2.0 / textureSize(sprite, 0); // gets size of single texel
        vec3 result = texture(sprite, TexCoords).rgb * weight[0]; // current fragment's contribution
        if(horizontal)
        {
            for(int i = 1; i < 5; ++i)
            {
                result += texture(sprite, TexCoords + vec2(tex_offset.x * i, 0.0)).rgb * weight[i];
                result += texture(sprite, TexCoords - vec2(tex_offset.x * i, 0.0)).rgb * weight[i];
            }
        }
        else
        {
            for(int i = 1; i < 5; ++i)
            {
                result += texture(sprite, TexCoords + vec2(0.0, tex_offset.y * i)).rgb * weight[i];
                result += texture(sprite, TexCoords - vec2(0.0, tex_offset.y * i)).rgb * weight[i];
            }
        }
        return result;
    }
    
    void main()
    {
        if(enableBlur)
        {
            vec3 color = blur();
            FragColor = spriteColor * vec4(color, 1.0);
        }
        else
        {
            FragColor = spriteColor * texture(sprite, TexCoords);
        }
    
    }
    )";
    static const char *rect_fragment =
            R"(
    #version 330 core
    out vec4 FragColor;
    
    uniform vec4 rectColor;
    
    void main()
    {
        FragColor = rectColor;
    }
    )";
    static const char *roundrect_texture_fragment =
            R"(
    #version 330 core
    
    uniform vec2 size;
    uniform vec3 spriteColor;

    uniform float alpha;
    uniform float radius;

    uniform sampler2D sprite;
    
    in vec2 TexCoords;
    
    // from IQ: https://iquilezles.org/articles/distfunctions2d
    float roundedSDF(vec2 distFromCenter, vec2 halfSize, float cornerRadius)
    {
        return length(max(abs(distFromCenter) - halfSize, 0.0)) - cornerRadius;
    }
    out vec4 FragColor;
    void main()
    {
        float distance = roundedSDF((size * 0.5) - (TexCoords * size), (size * 0.5) - radius - 1.0, radius);
        float smoothedAlpha = (1.0-smoothstep(0.0, 2.0, distance)) * alpha;
        vec4 col = vec4(spriteColor * texture2D(sprite, TexCoords).rgb, smoothedAlpha);
    	FragColor = col;
    }
    )";
    static const char *roundrect_outline_fragment =
            R"(
    #version 330 core
    
    uniform vec2 size;
    uniform vec2 location;

    uniform vec4 rectColor;
    uniform vec4 outlineColor;

    uniform float radius;
    uniform float thickness;

    in vec2 TexCoords;
    out vec4 FragColor;
    // from IQ: https://iquilezles.org/articles/distfunctions2d
    float roundedSDF(vec2 distFromCenter, vec2 halfSize, float cornerRadius)
    {
        return length(max(abs(distFromCenter) - halfSize + cornerRadius, 0.0)) - cornerRadius;
    }

    void main()
    {
        float distance = roundedSDF(gl_FragCoord.xy - location - (size * 0.5), (size * 0.5) + (thickness * 0.5) - 1.0, radius);
        float blendAmount = smoothstep(0.0, 2.0, abs(distance) - (thickness * 0.5));
        vec4 internalColor = (distance < 0.0) ? rectColor : vec4(outlineColor.rgb, 0.0);
        FragColor = mix(outlineColor, internalColor, blendAmount);
    }
    )";
    static const char *roundrect_fragment =
            R"(
    #version 330 core

    uniform vec2 size;
    uniform vec3 rectColor;
    uniform float alpha;
    uniform float radius;

    in vec2 TexCoords;
    out vec4 FragColor;
    float roundedSDF(vec2 distFromCenter, vec2 halfSize, float cornerRadius)
    {
        return length(max(abs(distFromCenter) - halfSize, 0.0)) - cornerRadius;
    }
    void main() 
    {
        float distance = roundedSDF((size * 0.5) - (TexCoords * size), (size * 0.5) - radius - 1.0, radius);
        float smoothedAlpha = (1.0 - smoothstep(0.0, 1.0, distance)) * alpha;
        FragColor = vec4(rectColor, smoothedAlpha);
    }
    )";
}
namespace Nacy {

    class NACY_API Shader {
    public:
        uint32_t ID;

        Shader();

        void Use() const;

        Shader &UseShader();

        void LoadFileAndCompile(const char *vertexPath, const char *fragmentPath);

        void Compile(const char *vertexCode, const char *fragmentCode);

        void AttachShader(unsigned int vertex, unsigned int fragment);

        unsigned int CreateShader(const char *shaderCode, const char *shaderType);

        void SetInt(const char *name, int num) const;

        void SetFloat(const char *name, float num) const;

        void SetDouble(const char *name, double num) const;

        void SetBool(const char *name, bool value) const;

        void SetVector1F(const char *name, const glm::vec1 &vec) const;

        void SetVector2F(const char *name, const glm::vec2 &vec) const;

        void SetVector3F(const char *name, const glm::vec3 &vec) const;

        void SetVector4F(const char *name, const glm::vec4 &vec) const;

        void SetMatrix2F(const char *name, const glm::mat2 &mat) const;

        void SetMatrix3F(const char *name, const glm::mat3 &mat) const;

        void SetMatrix4F(const char *name, const glm::mat4 &mat) const;

    private:
        static void checkCompileErrors(uint32_t shader, std::string type);
    };
}
