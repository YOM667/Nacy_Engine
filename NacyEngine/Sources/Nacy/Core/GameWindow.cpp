#include "pch.h"
#include "GameWindow.h"
#include "Nacy/Event/KeyEvent.h"
namespace Engine
{
	static bool GLFWInitialized = false;
	GameWindow::GameWindow(const WindowConfig& configs) : configs(configs)
	{
		this->init(this->configs);
	}
	GameWindow::~GameWindow()
	{
		this->destory();
	}
	GLFWwindow* GameWindow::Get()
	{
		return this->window;
	}
	void GameWindow::init(const WindowConfig& configs)
	{
		this->createGLSpace();

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
			}
		);
	}
	void GameWindow::createGLSpace()
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

		}
		/* Create the window by user's window configuration */
		this->window = glfwCreateWindow(this->configs.width,
			this->configs.height,
			this->configs.title.c_str(),
			nullptr,
			nullptr);

		Assert(window, "The window created failed");

		float maxWidth = GetSystemMetrics(SM_CXSCREEN);
		float maxHieght = GetSystemMetrics(SM_CYSCREEN);
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
			posX,
			posY,
			this->configs.width,
			this->configs.height,
			GLFW_DONT_CARE);

		glfwMakeContextCurrent(window);
		glViewport(0, 0, this->configs.width, this->configs.height);
		this->projection = glm::ortho(0.0f, this->GetWidth(), this->GetHeight(), 0.0f, -1.0f, 1.0f);

		if (glewInit() != GLEW_OK)
		{
			glfwTerminate();
		}
	}
	void GameWindow::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(this->window);
	}
	void GameWindow::clear()
	{
		glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void GameWindow::destory()
	{
		glfwDestroyWindow(this->window);
		glfwTerminate();
	}
	void GameWindow::setVSync(bool enabled)
	{

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