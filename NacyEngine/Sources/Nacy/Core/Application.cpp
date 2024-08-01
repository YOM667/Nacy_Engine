#include "pch.h"

#include "Application.h"
#include "Nacy/Manager/Input/InputManager.h"
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
	Application::Application(const WindowConfig& windowConfig)
		: running(false), FPS(0), loading(true)
	{

		this->window = std::make_shared<GameWindow>(windowConfig);

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
		Info("Set engine event handlers");
		this->window->setEventCallback(BIND_EVENT_FN(OnEvent));

		SceneManager::GetInstance()->SetWindowSize(Vector2(this->window->GetWidth(), this->window->GetHeight()));
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(OnKeyReleased));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMouseButtonPressed));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMoving));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
	}
	bool Application::OnKeyPressed(KeyPressedEvent& event)
	{
		InputManager::KeyAction(event.GetKeyCode(),KeyActionType::KEY_PRESSED);
		//if (SceneManager::GetInstance()->GetCurrentSceneID() != -1)
		//{
		//	SceneManager::GetInstance()->GetCurrentScene()->KeyPressed(event.GetKeyCode());
		//}

		return true;
	}
	bool Application::OnKeyReleased(KeyReleasedEvent& event)
	{
		InputManager::KeyAction(event.GetKeyCode(), KeyActionType::KEY_RELESED);
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
		InputManager::mouseX = event.GetX();
		InputManager::mouseY = event.GetY();
		//if (scene != nullptr)
		//{
		//	//SceneManager::GetInstance()->GetCurrentScene()->MouseMoving(event.GetX(), event.GetY());
		//}
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvent& event)
	{

		float desiredAspectRatio = 1280.0f / 720.0f;

		int widthOfViewport{}, heightOfViewport{};
		// These are two new values that we will be calculating in this function
		int lowerLeftCornerOfViewportX{}, lowerLeftCornerOfViewportY{};

		float requiredHeightOfViewport = event.GetWidth() * (1.0f / desiredAspectRatio);
		if (requiredHeightOfViewport > event.GetHeight())
		{
			float requiredWidthOfViewport = event.GetHeight() * desiredAspectRatio;
			if (requiredWidthOfViewport > event.GetWidth())
			{
				std::cout << "Error: Couldn't find dimensions that preserve the aspect ratio\n";
			}
			else
			{
				// Remember that if we reach this point you will observe vertical bars
				// on the left and right
				widthOfViewport = static_cast<int>(requiredWidthOfViewport);
				heightOfViewport = event.GetHeight();

				// The widths of the two vertical bars added together are equal to the
				// difference between the width of the framebuffer and the width of the viewport
				float widthOfTheTwoVerticalBars = event.GetWidth() - widthOfViewport;

				// Set the X position of the lower left corner of the viewport equal to the
				// width of one of the vertical bars. By doing this, we center the viewport
				// horizontally and we make vertical bars appear on the left and right
				lowerLeftCornerOfViewportX = static_cast<int>(widthOfTheTwoVerticalBars / 2.0f);
				// We don't need to center the viewport vertically because we are using the
				// height of the framebuffer as the height of the viewport
				lowerLeftCornerOfViewportY = 0;
			}
		}
		else
		{
			// Remember that if we reach this point you will observe horizontal bars
			// on the top and bottom
			widthOfViewport = event.GetWidth();
			heightOfViewport = static_cast<int>(requiredHeightOfViewport);

			// The heights of the two horizontal bars added together are equal to the difference
			// between the height of the framebuffer and the height of the viewport
			float heightOfTheTwoHorizontalBars = event.GetHeight() - heightOfViewport;

			// We don't need to center the viewport horizontally because we are using the
			// width of the framebuffer as the width of the viewport
			lowerLeftCornerOfViewportX = 0;
			// Set the Y position of the lower left corner of the viewport equal to the
			// height of one of the vertical bars. By doing this, we center the viewport
			// vertically and we make horizontal bars appear on the top and bottom
			lowerLeftCornerOfViewportY = static_cast<int>(heightOfTheTwoHorizontalBars / 2.0f);
		}

		// Call glViewport to specify the new drawing area
		// By specifying its lower left corner, we center it
		glViewport(lowerLeftCornerOfViewportX, lowerLeftCornerOfViewportY,
			widthOfViewport, heightOfViewport);
		this->window->SetWidth(event.GetWidth());
		this->window->SetHeight(event.GetHeight());

		//SceneManager::GetInstance()->SetWindowSize(Vector2(this->window->GetWidth(), this->window->GetHeight()));
		return true;
		/*auto aspect = event.GetWidth() / event.GetHeight();
		glViewport(0, 0, event.GetWidth(), event.GetHeight());
		glm::mat4 ortho(1.0f);
		if (aspect >= 1.0f)
			ortho = glm::ortho(0.0f * aspect, 1270.0f * aspect,800.0f,0.0f,1.0f,-1.0f);
		else
			ortho = glm::ortho(0.0f, 1270.0f, 800.0f / aspect, 0.0f / aspect, 1.0f, -1.0f);

		this->window->SetNewProjection(ortho);
		this->window->SetWidth(event.GetWidth());
		this->window->SetHeight(event.GetHeight());
		
		this->UpdateShader();
		return true;*/
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
		this->running = false;
		this->window->Destory();
	}

	void Application::Render(double delta)
	{
		this->window->Clear();
		SceneManager::GetInstance()->Render(delta);
		this->window->Update();
	}
	void Application::Update(double delta)
	{
		SceneManager::GetInstance()->Update(delta);
	}

	std::shared_ptr<GameWindow> Application::GetWindow()
	{
		return this->window;
	}
	int Application::GetFPS()
	{
		return this->FPS;
	}
}

