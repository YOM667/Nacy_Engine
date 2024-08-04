#pragma once

#include "Nacy/Core/Event/Events/KeyEvent.hpp"
#include "Nacy/Core/Event/Events/WindowEvent.hpp"
#include "Nacy/Core/Event/Events/MouseEvent.hpp"
#include "GameWindow.h"

namespace Nacy {

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
    *		//After initialize all resource and loaders, you can display a screen
    *		this->display(new Screen());
    *	}
    * }
    *
    */
    class Application {
    public:
        /* To load renderer shader and initialize graphic */
        NACY_API explicit Application(const WindowConfig &config);
        /* To start the engine */
        NACY_API void Start();

        NACY_API void ShutDown();
        //Get Application's field
        NACY_API std::shared_ptr<GameWindow> GetWindow();

        NACY_API int GetFPS();

        //Application default field
        bool running, loading;
        int FPS;
    private:
        void OnEvent(Event &e);

        bool OnKeyPressed(KeyPressedEvent &event);

        bool OnKeyReleased(KeyReleasedEvent &event);

        bool OnMouseButtonPressed(MouseButtonPressedEvent &event);

        bool OnMouseMoving(MouseMovedEvent &event);

        bool OnWindowResize(WindowResizeEvent &event);

        void Render(double delta);

        void Update(double delta);

        std::shared_ptr<GameWindow> window;


    };
}
