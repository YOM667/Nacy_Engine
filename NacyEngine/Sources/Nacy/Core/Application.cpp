#include "pch.h"

#include "Application.h"
#include "Nacy/Manager/Input/InputManager.h"
#include "Nacy/Manager/Assets/ResourceManager.h"
#include "Nacy/Manager/Shader/Shader.h"
#include "Nacy/Util/Utilities.h"
#include "Nacy/Util/Logger/Logger.h"
#include "Nacy/Manager/Scene/SceneManager.h"
#include <Nacy/Math/Vector.h>

namespace Nacy {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    static int lowerLeftCorner = 0;
    static int lowerTopCorner = 0;
    static bool windowCreated = false;

    Application::Application(const WindowConfig &windowConfig)
            : running(false), FPS(0), loading(true) {

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
        ResourceManager::LoadFont("NacyRes/Comici.ttf", 42, "comici_small");
        ResourceManager::LoadFont("NacyRes/Comici.ttf", 32, "comici_smallA");
        Info("Set engine event handlers");
        this->window->setEventCallback(BIND_EVENT_FN(OnEvent));

        SceneManager::GetInstance()->SetWindowSize(Vector2(this->window->GetWidth(), this->window->GetHeight()));
    }

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPressed));
        dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(OnKeyReleased));
        dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(OnMouseButtonPressed));
        dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMoving));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
    }

    bool Application::OnKeyPressed(KeyPressedEvent &event) {
        InputManager::KeyAction(event.GetKeyCode(), KeyActionType::KEY_PRESSED);
        return true;
    }

    bool Application::OnKeyReleased(KeyReleasedEvent &event) {
        InputManager::KeyAction(event.GetKeyCode(), KeyActionType::KEY_RELESED);
        return true;
    }

    bool Application::OnMouseButtonPressed(MouseButtonPressedEvent &event) {
        auto scene = SceneManager::GetInstance()->GetCurrentScene();
        if (scene != nullptr)
            scene->OnMouseButton(event.GetMouseButton());
        return true;
    }

    bool Application::OnMouseMoving(MouseMovedEvent &event) {
        InputManager::mouseX = event.GetX();
        InputManager::mouseY = event.GetY();
        if (lowerLeftCorner != 0) {
            InputManager::mouseX = event.GetX() + lowerLeftCorner;
        }
        if (lowerTopCorner != 0) {
            InputManager::mouseY = event.GetY() + lowerTopCorner;
        }
        return true;
    }

    void UpdateShader(glm::mat4 projection) {
        ResourceManager::GetShader("textureShader").
                        UseShader()
                .SetMatrix4F("projection", projection);
        ResourceManager::GetShader("textShader")
                .UseShader()
                .SetMatrix4F("projection", projection);
        ResourceManager::GetShader("roundTextureShader")
                .UseShader()
                .SetMatrix4F("projection", projection);
        ResourceManager::GetShader("rectShader")
                .UseShader()
                .SetMatrix4F("projection", projection);
        ResourceManager::GetShader("roundedRectOutlineShader")
                .UseShader()
                .SetMatrix4F("projection", projection);
        ResourceManager::GetShader("roundedRectShader")
                .UseShader()
                .SetMatrix4F("projection", projection);
    }

    bool Application::OnWindowResize(WindowResizeEvent &event) {
        glViewport(0, 0, event.GetWidth(), event.GetHeight());
        this->window->SetWidth(event.GetWidth());
        this->window->SetHeight(event.GetHeight());
        this->window->UpdateProjection();
        UpdateShader(this->window->GetProjection());
        SceneManager::GetInstance()->Resize(Vector2(event.GetWidth(),event.GetHeight()));
        return true;
    }

    void Application::Start() {
        running = true;
        auto deltaTime = 0.0;
        auto lastFrame = 0.0;
        auto lastTime = Utility::GetNanoTime();

        auto frameCounter = 0LL;

        auto unprocessedTime = 0.0;

        auto frame = 0;
        while (running) {
            auto render = false;
            auto startTime = Utility::GetNanoTime();
            auto passedTime = startTime - lastTime;

            lastTime = startTime;
            unprocessedTime += (double) passedTime / 1000000000L;

            auto currentFrame = static_cast<float>(glfwGetTime());
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            frameCounter += passedTime;


            while (unprocessedTime > 0.001) {
                render = true;
                unprocessedTime -= 0.001;
                if (glfwWindowShouldClose(this->window->Get())) {
                    Info("Application will destory");
                    return;
                }
                if (frameCounter >= 1000000000L) {
                    this->FPS = frame;
                    frame = 0;
                    frameCounter = 0;
                }
            }

            if (render) {
                this->Update(deltaTime);
                this->Render(deltaTime);
                frame++;
            }
        }
    }

    void Application::ShutDown() {
        this->running = false;
        this->window->Destory();
    }

    void Application::Render(double delta) {
        this->window->Clear();
        SceneManager::GetInstance()->Render(delta);
        this->window->Update();
    }

    void Application::Update(double delta) {
        SceneManager::GetInstance()->Update(delta);
    }

    std::shared_ptr<GameWindow> Application::GetWindow() {
        return this->window;
    }

    int Application::GetFPS() {
        return this->FPS;
    }
}

