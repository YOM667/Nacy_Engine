#pragma once
#include "Nacy/Core/Core.h"
#include "Scene.h"
namespace Nacy
{
	class SceneManager
	{
	private:
		SceneManager();
		SceneManager(const SceneManager& signal) = delete;
		const SceneManager& operator=(const SceneManager& signal) = delete;

		static SceneManager* instance;
	public:

		NACY_API void Render(double delta);
		NACY_API void Update(double delta);

		NACY_API void SetWindowSize(const Vector2& size);

		NACY_API static SceneManager* GetInstance();
		
		NACY_API void DisplayScene(Scene* scene);

		NACY_API int GetCurrentSceneID();
		NACY_API Graphic* GetGraphic();

	private:

		Vector2 size;
		Graphic* graphic;
		Scene* scene;
	};
}