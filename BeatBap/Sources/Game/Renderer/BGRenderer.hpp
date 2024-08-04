#include <NacyEngine.h>

class BGRenderer {
private:
    Nacy::Renderer *renderer;
public:
    BGRenderer() {
        this->renderer = new Nacy::Renderer(Nacy::ResourceManager::GetShader("background"));
    }

    ~BGRenderer() {
        if (this->renderer != nullptr) {
            delete this->renderer;
        }
    }

    void SetProjection() {
        this->renderer->GetShader().SetMatrix4F("projection",
                                                glm::ortho(0.0f, this->renderer->size.x, this->renderer->size.y, 0.0f));
    }

    void Draw(const Nacy::Vector2 &position, const Nacy::Vector2& size, float alpha) {

        Nacy::Shader &shader = this->renderer->GetShader();
        shader.Use();
        shader.SetFloat("alpha", alpha / 255.0f);
        shader.SetFloat("iTime", static_cast<float>(Utility::GetGLFWTime()));
        shader.SetVector2F("iResolution", glm::vec2(size.x / 2.0f, size.y / 2.0f));
        renderer->Draw(position, size);
    }
};