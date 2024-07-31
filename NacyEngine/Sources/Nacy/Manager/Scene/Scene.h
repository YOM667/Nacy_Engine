#pragma once

#include "Nacy/Object/GameObject.h"
#include "Nacy/Render/Graphic.hpp"

namespace Nacy
{
	class Scene
	{
	public:

		NACY_API Scene(int id);
		NACY_API virtual void Init() {};
		NACY_API virtual void Update(double delta) {};
		NACY_API virtual void DrawBackground() {};


		NACY_API void Render(double delta);
		NACY_API void Exit();


		NACY_API void AddGameObject(const std::string& name, GameObject* node);
		NACY_API void RemoveGameObject(const std::string& name);
		NACY_API GameObject* GetGameObject(const std::string& name);

		NACY_API void SetGraphic(Graphic* graphic);
		NACY_API void SetWindowSize(float screenWidth, float screenHeight);

		NACY_API constexpr int GetID();
	protected:
		Graphic* graphic;
		float screenWidth, screenHeight;
		float mouseX, mouseY;
		int id;
	private:
		std::vector<std::pair<std::string, GameObject*>> objects;
	};


}
