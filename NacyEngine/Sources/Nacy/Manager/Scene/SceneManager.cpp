#include "pch.h"
#include "SceneManager.h"

namespace Nacy
{
	SceneManager* SceneManager::instance = nullptr;

	SceneManager::SceneManager()
	{
		auto shape = new ShapeRenderer();

		auto text = new FontRenderer();

		auto sprite = new SpriteRenderer();

		this->graphic = new Graphic(sprite, shape, text);
	}

	SceneManager::~SceneManager()
	{
		if (this->graphic != nullptr)
		{
			delete this->graphic;
			this->graphic = nullptr;
		}
		if (this->scene != nullptr)
		{
			delete this->scene;
			this->scene = nullptr;
		}
	}


	void SceneManager::Render(double delta)
	{
		this->scene->Render(delta);
	}

	void SceneManager::Update(double delta)
	{
		this->scene->Update(delta);
	}

	void SceneManager::SetWindowSize(const Vector2& size)
	{
		this->size = size;
	}

	SceneManager* SceneManager::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager();
		}
		return instance;
	}
	void SceneManager::DisplayScene(Scene* newScene)
	{
		if (this->scene != nullptr)
		{
			this->scene->Exit();
		}

		delete this->scene;
		this->scene = nullptr;
		if (newScene != nullptr)
		{
			this->scene = newScene;
			this->scene->SetGraphic(this->graphic);
			this->scene->SetWindowSize(this->size.x, this->size.y);
			this->scene->Init();
		}

	}
	Scene* SceneManager::GetCurrentScene()
	{
		return this->scene;
	}
	Graphic* SceneManager::GetGraphic()
	{
		return this->graphic;
	}
}

