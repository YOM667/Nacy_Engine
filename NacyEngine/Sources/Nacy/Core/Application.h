#pragma once

#include "Nacy/Render/Graphic.hpp"
#include "Nacy/Manager/Scene/Scene.h"

#include "Nacy/Core/Event/Events/KeyEvent.hpp"
#include "Nacy/Core/Event/Events/MouseEvent.hpp"
#include "GameWindow.h"

namespace Nacy
{

	/*
	* You need to extend the NApplication to initialize the engine
	* 
	* For Example:
	* 
	* class Game : public NApplication
	* {
	* public:
	*	Game() : NApplication(createWindow("Game", true, 1270, 800, true, false ))
	*	{
	*		//After initialize all resource and loaderss, you can display a screen
	*		this->display(new Screen());
	*	}
	* }
	* 
	*/
	class Application
	{
	public:
		/* To load renderer shader and initialize graphic */
		NACY_API Application(GameWindow* gameWindow);

		NACY_API ~Application();
		/* To start the engine */
		NACY_API void Start();
		NACY_API void ShutDown();
		//Get Application's field
		NACY_API inline GameWindow* GetWindow();
		NACY_API inline int GetFPS();
		NACY_API static GameWindow* CreateGameWindow(const WindowConfig& config);
		//Application default field
		bool running, loading;
		int FPS;
	private:
		void OnEvent(Event& e);

		bool OnKeyPressed(KeyPressedEvent& event);
		bool OnKeyReleased(KeyReleasedEvent& event);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
		bool OnMouseMoving(MouseMovedEvent& event);

		void Render(double delta);
		void Update(double delta);

		GameWindow* window;


	};
}
