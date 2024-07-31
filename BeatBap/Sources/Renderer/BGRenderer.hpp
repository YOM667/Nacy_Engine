#include <NacyEngine.h>
class BGRenderer
{
private:
	Nacy::Renderer* renderer;
public:
	BGRenderer()
	{
		this->renderer = new Nacy::Renderer(Nacy::ResourceManager::GetShader("background"));
	}
	~BGRenderer()
	{
		if (this->renderer != nullptr)
		{
			delete this->renderer;
		}
	}
	void Draw(float x, float y, float width, float height, float alpha)
	{
		renderer->x = x;
		renderer->y = y;
		renderer->width = width;
		renderer->height = height;

		Nacy::Shader& shader = this->renderer->GetShader();
		shader.Use();
		shader.SetFloat("alpha", alpha / 255.0f);
		shader.SetFloat("iTime", static_cast<float>(Utility::GetGLFWTime()));
		shader.SetVector2F("iResolution", glm::vec2(this->renderer->width, this->renderer->height));
		renderer->Draw();
	}
};