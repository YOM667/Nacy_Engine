#pragma once

#include "Nacy/Core/Core.h"
#include "Nacy/Core/Event/Event.h"

namespace Nacy
{

	using EventCallbackFn = std::function<void(Event&)>;

	struct NACY_API Mouse
	{
		int mouseX, mouseY;
		int action;
		int button;
		int mods;
	};
	struct NACY_API KeyBoard
	{
		int key; 
		int scancode; 
		int action; 
		int mods;
	};
	/* 
	* User's window configuration. When user create a application, he can use 
	* the struct "WindowConfig" to custom window styles.
	* 
	* User need to use it while provide some pragam or use the Maple default 
	* configuration.
	* 
	* User can create "new WindowConfig()" by the way or provide
	* title, positionX, positionY, width, height, resizeable, visiable pragam.
	*/
	struct NACY_API WindowConfig
	{
		// Window's visiale title 
		const char* title;
		// Window's position in user's screen.
		float positionX, positionY;
		// Window's size
		float width, height;
		// User can change the window's size?
		bool resizeable;
		// The window can display in user's screen?
		bool visiable;
		// when the field is true,window will centered;
		bool centered;

		WindowConfig(const char* title = "Game",
			bool centered = true,
			float width = 960,
			float height = 540,
			bool visiable = true,
			bool resizeable = true) :
			title(title), positionX(-1), positionY(-1),
			centered(centered),
			width(width), height(height),
			visiable(visiable), resizeable(resizeable)
		{
			
		}
	};
	/*
	* User can create a "GameWindow" to render griphic or achieve game function
	*/
	class GameWindow
	{
	public:
		//when User create a GameWindow, the constuctor will inovke "init()" method
		NACY_API GameWindow(const WindowConfig& configs);
		//when the process will destory, ~GameWindow() will invoke "destory()" method
		NACY_API ~GameWindow();
		// get the glfw window instance
		NACY_API GLFWwindow* Get();
		//User can use "update()" method to flush window fream and recive User's operate
		NACY_API void Update();
		NACY_API void Clear();
		//User can use "destory()" method to shutdown the window
		NACY_API void Destory();
		NACY_API void SetVSync(bool enabled);

		//get window's size
		NACY_API inline float GetWidth();
		NACY_API inline float GetHeight();
		NACY_API inline glm::mat4 GetProjection();

		NACY_API void setEventCallback(const EventCallbackFn& callback);
	private:
		//Initialise glfw and glew. Load WindowConfigs
		NACY_API void Init(const WindowConfig& configs);
		NACY_API void CreateGLSpace();

		GLFWwindow* window;
		WindowConfig configs;

		glm::mat4 projection;

		struct WindowData
		{
			const char* Title;
			float Width = 0.0f;
			float Height = 0.0f;
			bool VSync = true;

			EventCallbackFn EventCallback;
		};

		WindowData windowData;
	};
}


