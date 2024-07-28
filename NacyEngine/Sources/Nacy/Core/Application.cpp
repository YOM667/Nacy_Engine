#include "pch.h"

#include "Application.h"

#include "Nacy/Manager/Assets/ResourceManager.h"
#include "Nacy/Manager/Shader/Shader.h"
#include "Nacy/Util/Utilities.h"
#include "Nacy/Util/Logger/Logger.h"
#include "Nacy/Manager/Scene/SceneManager.h"
#include <Nacy/Math/Vector.h>
namespace Nacy
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	static bool windowCreated = false;
	Application::Application(GameWindow* gameWindow)
		: running(false), FPS(0) , window(gameWindow), loading(true)
	{
		auto projection = this->window->GetProjection();
		Info("Loading engine graphic shaders");
		ResourceManager::LoadShader(
			Shaders::texture_vertex,
			Shaders::texture_fragment,
			"textureShader").UseShader().SetMatrix4F("projection", projection);

		ResourceManager::LoadShader(
			Shaders::texture_vertex,
			Shaders::text_fragment,
			"textShader").UseShader().SetMatrix4F("projection", projection);
		
		ResourceManager::LoadShader(
			Shaders::texture_vertex,
			Shaders::roundrect_texture_fragment,
			"roundTextureShader").UseShader().SetMatrix4F("projection", projection);

		ResourceManager::LoadShader(
			Shaders::shape_vertex,
			Shaders::rect_fragment,
			"rectShader").UseShader().SetMatrix4F("projection", projection);
		ResourceManager::LoadShader(
			Shaders::texture_vertex,
			Shaders::roundrect_outline_fragment,
			"roundedRectOutlineShader").UseShader().SetMatrix4F("projection", projection);
		ResourceManager::LoadShader(
			Shaders::texture_vertex,
			Shaders::roundrect_fragment,
			"roundedRectShader").UseShader().SetMatrix4F("projection", projection);


		Info("Loading engine logo icon");
		ResourceManager::LoadTexture2D("NacyRes/nacy.png", true, "nacy");

		Info("Loading engine ttf font");
		ResourceManager::LoadFont("NacyRes/Comici.ttf", 64, "comici");
		
		Info("Loading engine graphic renderer");


		Info("Set engine event handlers");
		this->window->setEventCallback(BIND_EVENT_FN(OnEvent));

		Info("Display engine splash screen");
		SceneManager::GetInstance()->SetWindowSize(Vector2(this->window->GetWidth(), this->window->GetHeight()));
	}
	Application::~Application()
	{
		if (!running)
		{
			if (this->window != nullptr) { delete this->window; }
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(OnKeyReleased));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMouseButtonPressed));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMoving));
	}
	bool Application::OnKeyPressed(KeyPressedEvent& event)
	{
		//if (scene != nullptr)
		//{
		//	//SceneManager::GetInstance()->GetCurrentScene()->KeyPressed(event.GetKeyCode());
		//}

		return true;
	}
	bool Application::OnKeyReleased(KeyReleasedEvent& event)
	{
		//if (scene != nullptr)
		//{
		//	//SceneManager::GetInstance()->GetCurrentScene()->KeyReleased(event.GetKeyCode());
		//}
		return true;
	}
	bool Application::OnMouseButtonPressed(MouseButtonPressedEvent& event)
	{

		//if (scene != nullptr)
		//{
		//	//SceneManager::GetInstance()->GetCurrentScene()->MouseButtonPressed(event.GetMouseButton());
		//}

		return true;
	}
	bool Application::OnMouseMoving(MouseMovedEvent& event)
	{
		//if (scene != nullptr)
		//{
		//	//SceneManager::GetInstance()->GetCurrentScene()->MouseMoving(event.GetX(), event.GetY());
		//}
		return true;
	}
	void Application::Start()
	{
		running = true;

		auto deltaTime = 0.0;
		auto lastFrame = 0.0;
		auto lastTime = Utility::GetNowTime();

		auto frameCounter = 0LL;

		auto unprocessedTime = 0.0;

		auto frame = 0;
		while (running)
		{
			auto render = false;
			auto startTime = Utility::GetNowTime();
			auto passedTime = startTime - lastTime;

			lastTime = startTime;
			unprocessedTime += (double)passedTime / 1000000000L;

			auto currentFrame = static_cast<float>(glfwGetTime());
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			frameCounter += passedTime;

			
			while (unprocessedTime > 0.001)
			{
				render = true;
				unprocessedTime -= 0.001;
				if (glfwWindowShouldClose(this->window->Get()))
				{
					Info("Application will destory");
					return;
				}
				if (frameCounter >= 1000000000L)
				{
					this->FPS = frame;
					frame = 0;
					frameCounter = 0;
				}
			}

			if (render)
			{
				this->Update(deltaTime);
				this->Render(deltaTime);
				frame++;
			}
		}
	}
	void Application::ShutDown()
	{
		glfwTerminate();
	}

	void Application::Render(double delta)
	{
		this->window->Clear();
		SceneManager::GetInstance()->Render(delta);
		this->window->Update();
	}
	void Application::Update(double delta)
	{
		auto size = Vector2(this->window->GetWidth(), this->window->GetHeight());
		SceneManager::GetInstance()->SetWindowSize(size);
		SceneManager::GetInstance()->Update(delta);
	}
	GameWindow* Application::GetWindow()
	{
		return this->window;
	}
	int Application::GetFPS()
	{
		return this->FPS;
	}
	GameWindow* Application::CreateGameWindow(const WindowConfig& config)
	{
		auto Window = new GameWindow(config);
		if (Window != nullptr)
		{
			windowCreated = true;
		}
		return Window;
	}
}

