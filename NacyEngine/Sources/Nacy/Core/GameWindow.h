#pragma once

#include "Nacy/Core/Core.h"
#include "Nacy/Core/Event/Event.h"

namespace Nacy {

    using EventCallbackFn = std::function<void(Event &)>;

    /*
    * User's window configuration. When user create an application, he can use
    * the struct "WindowConfig" to custom window styles.
    *
    * User need to use it while provide some program or use the Maple default
    * configuration.
    *
    * User can create "new WindowConfig()" by the way or provide
    * title, positionX, positionY, width, height, resizeable, visible program.
    */
    struct NACY_API WindowConfig {
        // Window's visible title
        const char *title;
        // Window's position in user's screen.
        float positionX, positionY;
        // Window's size
        float width, height;
        // User can change the window's size?
        bool resizeable;
        // The window can display in user's screen?
        bool visible;
        // when the field is true,window will center;
        bool centered;

        explicit WindowConfig(const char *title = "Game",
                     bool centered = true,
                     float width = 960,
                     float height = 540,
                     bool visiable = true,
                     bool resizeable = true) :
                title(title), positionX(-1), positionY(-1),
                centered(centered),
                width(width), height(height),
                visible(visiable), resizeable(resizeable) {

        }
    };

    /*
    * User can create a "GameWindow" to render griphic or achieve game function
    */
    class GameWindow {
    public:
        //when User create a GameWindow, the constructor will invoke "init()" method
        NACY_API explicit GameWindow(const WindowConfig &configs);
        //when the process will destory, ~GameWindow() will invoke "destroy()" method
        NACY_API ~GameWindow();
        // get the glfw window instance
        NACY_API GLFWwindow *Get();
        //User can use "update()" method to flush window frame and receive Users' operate
        NACY_API void Update();

        NACY_API void Clear();
        //User can use "destroy()" method to shutdown the window
        NACY_API void Destory();

        NACY_API void SetVSync(bool enabled);

        //get window's size
        NACY_API float GetWidth();

        NACY_API float GetHeight();

        NACY_API void SetWidth(float width);

        NACY_API void SetHeight(float height);

        NACY_API glm::mat4 GetProjection();

        NACY_API void UpdateProjection();

        NACY_API void setEventCallback(const EventCallbackFn &callback);

    private:
        //Initialise glfw and glew. Load WindowConfigs
        NACY_API void Init(const WindowConfig &configs);

        NACY_API void CreateGLSpace();

        GLFWwindow *window;
        WindowConfig configs;

        glm::mat4 projection;

        struct WindowData {
            const char *Title;
            float Width = 0.0f;
            float Height = 0.0f;
            bool VSync = true;

            EventCallbackFn EventCallback;
        };

        WindowData windowData;
    };
}


