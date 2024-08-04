#include "pch.h"
#include "Sprite.h"
#include "Nacy/Manager/OpenGL/GLManager.h"
#include "Nacy/Manager/Assets/ResourceManager.h"

namespace Nacy {

    SpriteRenderer::SpriteRenderer() {
        this->spriteRenderer = new Renderer(Nacy::ResourceManager::GetShader("textureShader"));
        this->spriteRoundRenderer = new Renderer(Nacy::ResourceManager::GetShader("roundTextureShader"));
        this->spriteRenderer->GetShader().UseShader().SetInt("sprite", 0);
        this->spriteRoundRenderer->GetShader().UseShader().SetInt("sprite", 0);

    }

    SpriteRenderer::~SpriteRenderer() {

    }

    void
    SpriteRenderer::DrawSprite(Texture2D &texture,const Vector2 &position, const Vector2 &size, const RGBA &color) {
        glm::mat4 transform(1.0f);
        this->spriteRenderer->GetShader().Use();
        transform = glm::translate(transform, glm::vec3(position.x, position.y, 0.0f));
        transform = glm::scale(transform, glm::vec3(size.x, size.y, 1.0f));
        this->spriteRenderer->GetShader().SetMatrix4F("transform", transform);
        this->spriteRenderer->GetShader().SetVector4F("spriteColor", glm::vec4(color.red / 255.0f, color.green / 255.0f,
                                                                               color.blue / 255.0f,
                                                                               color.alpha / 255.0f));

        GL::GLManager::Blend();
        GL::GLManager::BlendFunc(NACY_GL_SRC_ALPHA, NACY_GL_ONE_MINUS_SRC_ALPHA);
        glActiveTexture(GL_TEXTURE0);
        texture.Bind();
        glBindVertexArray(this->spriteRenderer->GetVAO());
        glDrawElements(NACY_GL_TRIANGLES, 6, NACY_GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glBindTexture(NACY_GL_TEXTURE_2D, 0);
        GL::GLManager::DisableBlend();
    }

    void
    SpriteRenderer::DrawRoundedSprite(Texture2D &texture,const Vector2 &position, const Vector2 &size, float radius,
                                      float scale, const RGBA &color) {
        glm::mat4 transform(1.0f);
        this->spriteRoundRenderer->GetShader().Use();
        transform = glm::translate(transform, glm::vec3(position.x, position.y, 0.0f));

        transform = glm::translate(transform, glm::vec3(0.5f * (size.x), 0.5f * (size.y), 0.0f));
        transform = glm::scale(transform, glm::vec3(scale, scale, 1.0f));
        transform = glm::translate(transform, glm::vec3(-0.5f * (size.x), -0.5f * (size.y), 0.0f));

        transform = glm::scale(transform, glm::vec3(size.x, size.y, 1.0f));


        this->spriteRoundRenderer->GetShader().SetMatrix4F("transform", transform);
        this->spriteRoundRenderer->GetShader().SetVector3F("spriteColor",
                                                           glm::vec3(color.red / 255.0f, color.green / 255.0f,
                                                                     color.blue / 255.0f));
        this->spriteRoundRenderer->GetShader().SetVector2F("size", glm::vec2(size.x, size.y));
        this->spriteRoundRenderer->GetShader().SetFloat("alpha", color.alpha / 255.0f);
        this->spriteRoundRenderer->GetShader().SetFloat("radius", radius);

        GL::GLManager::Blend();
        GL::GLManager::BlendFunc(NACY_GL_SRC_ALPHA, NACY_GL_ONE_MINUS_SRC_ALPHA);
        glActiveTexture(GL_TEXTURE0);
        texture.Bind();
        glBindVertexArray(this->spriteRoundRenderer->GetVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);

        GL::GLManager::DisableBlend();

    }

}
