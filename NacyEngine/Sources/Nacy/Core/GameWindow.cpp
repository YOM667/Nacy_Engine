#include "pch.h"
#include "GameWindow.h"

#include "Nacy/Core/Event/Events/KeyEvent.hpp"
#include "Nacy/Core/Event/Events/MouseEvent.hpp"
namespace Nacy
{
	static bool GLFWInitialized = false;
	GameWindow::GameWindow(const WindowConfig& configs) : configs(configs)
	{
		this->Init(this->configs);
	}
	GameWindow::~GameWindow()
	{
		this->Destory();
	}
	GLFWwindow* GameWindow::Get()
	{
		return this->window;
	}
	void GameWindow::Init(const WindowConfig& configs)
	{
		this->CreateGLSpace();

		windowData.Title = configs.title;
		windowData.Width = configs.width;
		windowData.Height = configs.height;

		glfwSetWindowUserPointer(this->window, &windowData);

		glfwSetKeyCallback(this->window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS: 
					{ 
						KeyPressedEvent event(key, 0);	
						data.EventCallback(event);	
						break; 
					}

					case GLFW_RELEASE: 
					{ 
						KeyReleasedEvent event(key);	
						data.EventCallback(event);	
						break; 
					}
					case GLFW_REPEAT: 
					{ 
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);	
						break; 
					}
				}
			});
		glfwSetMouseButtonCallback(this->window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS: { MouseButtonPressedEvent event(button);	data.EventCallback(event);	break; }
				case GLFW_RELEASE: { MouseButtonReleasedEvent event(button);	data.EventCallback(event);	break; }
				}
			}
		);

		glfwSetScrollCallback(this->window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			}
		);

		glfwSetCursorPosCallback(this->window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xpos, (float)ypos);
				data.EventCallback(event);
			}
		);
	}
	void GameWindow::CreateGLSpace()
	{
		if (!GLFWInitialized)
		{
			bool glfwInitSuccess = glfwInit();
			Assert(glfwInitSuccess, "The glfw init failed");
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			/* The user's window configuration */
			glfwWindowHint(GLFW_RESIZABLE, configs.resizeable);
			glfwWindowHint(GLFW_VISIBLE, configs.visiable);
			glfwWindowHint(GLFW_SAMPLES, 4);

		}
		/* Create the window by user's window configuration */
		this->window = glfwCreateWindow(static_cast<int>(this->configs.width),
			static_cast<int>(this->configs.height),
			this->configs.title,
			nullptr,
			nullptr);

		Assert(window, "The window created failed");

		float maxWidth = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
		float maxHieght = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));
		float posX = 0.0f, posY = 0.0f;
		if (this->configs.positionX == -1 && this->configs.positionY == -1)
		{
			posX = (maxWidth / 2) - (this->configs.width / 2);
			posY = (maxHieght / 2) - (this->configs.height / 2);
		}
		else
		{
			posX = this->configs.positionX;
			posY = this->configs.positionY;
		}
		/* Set the window position */
		glfwSetWindowMonitor(window,
			nullptr,
			static_cast<int>(posX),
			static_cast<int>(posY),
			static_cast<int>(this->configs.width),
			static_cast<int>(this->configs.height),
			GLFW_DONT_CARE);

		glfwMakeContextCurrent(window);
		glViewport(0, 0, static_cast<int>(this->configs.width), static_cast<int>(this->configs.height));
		this->SetVSync(true);
		this->projection = glm::ortho(0.0f, this->GetWidth(), this->GetHeight(), 0.0f, -1.0f, 1.0f);

		if (glewInit() != GLEW_OK)
		{
			glfwTerminate();
		}
	}
	void GameWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
	void GameWindow::Clear()
	{
		glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void GameWindow::Destory()
	{
		glfwDestroyWindow(this->window);
		glfwTerminate();
	}
	void GameWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
	}
	float GameWindow::GetWidth()
	{
		return this->configs.width;
	}
	float GameWindow::GetHeight()
	{
		return this->configs.height;
	}
	inline glm::mat4 GameWindow::GetProjection()
	{
		return this->projection;
	}
	inline void GameWindow::setEventCallback(const EventCallbackFn& callback)
	{
		this->windowData.EventCallback = callback;
	}
}