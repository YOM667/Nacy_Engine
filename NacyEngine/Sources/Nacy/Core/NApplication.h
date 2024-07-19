#pragma once

#include "GameWindow.h"
#include "Nacy/Render/Graphic.h"
#include "Nacy/Render/Screen.h"
#include "Nacy/Event/KeyEvent.h"
#include "Nacy/Render/SplashScreen.h"
#include "Nacy/Render/Scene.h"
namespace Engine
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
	class NACY_API NApplication
	{
	public:
		/* To load renderer shader and initialize graphic */
		NApplication(std::shared_ptr<GameWindow> gameWindow);

		~NApplication();
		/* To start the engine */
		void Start();
		/* 
		* display your custom screen
		* @pragam newScreen: a custom screen
		*/
		void displayScreen(Screen* newScreen);
		void displayScene(Scene* newScene);
		//Get Application's field
		std::shared_ptr<GameWindow> GetWindow();
		uint32_t GetFPS();
		//Application default field
		bool running;
	protected:
		uint32_t FPS;
		/* help user to create a window */
		std::shared_ptr<GameWindow> createWindow(const WindowConfig& config);
		std::shared_ptr<GameWindow> window;

		Screen* GetScreen();
		Graphic* GetGraphic();
	private:
		void onEvent(Event& e);

		bool onKeyPressed(KeyPressedEvent& event);
		bool onKeyReleased(KeyReleasedEvent& event);

		void render(float delta);
		void update(float delta);

		SplashScreen* splash;
		Scene* scene;
		Screen* screen;
		Graphic* graphic;
	};
}
