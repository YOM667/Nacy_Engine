#include "pch.h"
#include "NApplication.h"
#include "Nacy/Manager/ResourceManager.h"
#include "Nacy/Utilities.h"

#include "Nacy/Resources/Shaders.h"
#include "Nacy/Event/KeyEvent.h"

#include "Nacy/Render/SplashScreen.h"
namespace Engine
{
#define BIND_EVENT_FN(x) std::bind(&NApplication::x, this, std::placeholders::_1)

	static bool windowCreated = false;
	NApplication::NApplication(std::shared_ptr<GameWindow> gameWindow)
		: running(false), FPS(0) , window(gameWindow)
	{
		this->screen = nullptr;
		this->scene = nullptr;
		auto projection = this->window->GetProjection();
		ResourceManager::LoadShader(
			texture_vertex,
			texture_fragment,
			"textureShader").useShader().setMatrix4F("projection", projection);

		ResourceManager::LoadShader(
			texture_vertex,
			text_fragment,
			"textShader").useShader().setMatrix4F("projection", projection);

		ResourceManager::LoadShader(
			shape_vertex,
			rect_fragment,
			"rectShader").useShader().setMatrix4F("projection", projection);

		ResourceManager::LoadTexture2D("NacyRes/nacy.png", true, "nacy");

		ResourceManager::LoadFont("NacyRes/Comici.ttf", 64, "comici");
		
		auto shape = std::make_shared<ShapeRenderer>();

		auto text = std::make_shared<FontRenderer>();

		auto sprite = std::make_shared<SpriteRenderer>(ResourceManager::GetShader("textureShader"));
		
		this->graphic = new Graphic(sprite, shape, text);

		this->window->setEventCallback(BIND_EVENT_FN(onEvent));

		this->splash = new SplashScreen();
		this->splash->setScreenSize(this->window->GetWidth(), this->window->GetHeight());
		this->splash->setGraphic(this->graphic);

	}
	NApplication::~NApplication()
	{
		if (!running)
		{
			if (this->graphic != nullptr) { delete this->graphic; }
			if (this->screen != nullptr) { delete this->screen; }
			if (this->splash != nullptr) { delete this->splash; }
			if (this->scene != nullptr) { delete this->scene; }
		}
	}
	void NApplication::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(onKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(onKeyReleased));
	}
	bool NApplication::onKeyPressed(KeyPressedEvent& event)
	{
		this->screen->keyPressed(event.GetKeyCode());
		return true;
	}
	bool NApplication::onKeyReleased(KeyReleasedEvent& event)
	{
		this->screen->keyReleased(event.GetKeyCode());
		return true;
	}
	void NApplication::Start()
	{
		running = true;

		auto deltaTime = 0.0;
		auto lastFrame = 0.0;
		auto lastTime = Utilities::Time::getNowTime();

		auto frameCounter = 0LL;

		auto unprocessedTime = 0.0;

		auto frame = 0;
		while (running)
		{
			auto render = false;
			auto startTime = Utilities::Time::getNowTime();
			auto passedTime = startTime - lastTime;

			lastTime = startTime;
			unprocessedTime += (double)passedTime / 1000000000L;

			auto currentFrame = static_cast<float>(glfwGetTime());
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			frameCounter += passedTime;
			this->update(deltaTime);
			while (unprocessedTime > 0.001)
			{
				render = true;
				unprocessedTime -= 0.001;
				if (glfwWindowShouldClose(this->window->Get()))
				{
					info("Application will destory");
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
				this->render(deltaTime);
				frame++;
			}
		}
	}
	void NApplication::displayScreen(Screen* newScreen)
	{
		if (this->screen == nullptr)
		{
			this->screen = newScreen;
		}
		else if (this->screen != newScreen)
		{
			delete this->screen;
			this->screen = newScreen;
		}
		this->screen->setScreenSize(this->window->GetWidth(), this->window->GetHeight());
		this->screen->setGraphic(this->graphic);

		debug("Set a new Screen in window");
	}

	void NApplication::displayScene(Scene* newScene)
	{
		delete this->screen;
		this->screen = nullptr;
		if (this->scene == nullptr)
		{
			this->scene = newScene;
		}
		else if (this->scene != scene)
		{
			delete this->scene;
			this->scene = newScene;
		}
		this->scene->init();
	}

	void NApplication::render(float delta)
	{
		this->window->clear();

		if (this->splash->isFinished())
		{
			if (this->screen != nullptr)
			{
				this->screen->render(delta);
			}
		}
		else
		{
			this->splash->render(delta);
		}

		this->window->update();
	}
	void NApplication::update(float delta)
	{

	}
	std::shared_ptr<GameWindow> NApplication::GetWindow()
	{
		return this->window;
	}
	uint32_t NApplication::GetFPS()
	{
		return this->FPS;
	}
	Screen* NApplication::GetScreen()
	{
		return this->screen;
	}
	Graphic* NApplication::GetGraphic()
	{
		return this->graphic;
	}
	std::shared_ptr<GameWindow> NApplication::createWindow(const WindowConfig& config)
	{
		auto Window = std::make_shared<GameWindow>(config);
		if (Window != nullptr)
		{
			windowCreated = true;
		}
		return Window;
	}
}

