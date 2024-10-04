#include "pch.h"
#include "SceneManager.h"
#include <Nacy/Math/Vector.h>

namespace Nacy {
    SceneManager *SceneManager::instance = nullptr;

    SceneManager::SceneManager()
            : scene(nullptr) {
        Graphic::Init();
    }

    void SceneManager::Render(double delta) {
        this->scene->Render(delta);
    }

    void SceneManager::Update(double delta) {
        this->scene->UpdateMouse();
        this->scene->Update(delta);
    }

    void SceneManager::Resize(const Vector2 &size) {
        this->SetWindowSize(size);
        this->scene->Init();
    }

    void SceneManager::SetWindowSize(const Vector2 &size) {
        this->size = size;
        Graphic::UpdateWindowSize(size);
    
        if (scene != nullptr) {
            this->scene->SetWindowSize(this->size.x, this->size.y);
        }

    }

    SceneManager *SceneManager::GetInstance() {
        if (instance == nullptr) {
            instance = new SceneManager();
        }
        return instance;
    }

    void SceneManager::DisplayScene(Scene *newScene) {
        if (this->scene != nullptr) {
            this->scene->Exit();
        }

        delete this->scene;
        this->scene = nullptr;
        if (newScene != nullptr) {
            this->scene = newScene;
            this->scene->SetWindowSize(this->size.x, this->size.y);
            this->scene->PreInit();
            this->scene->Init();
        }

    }

    int SceneManager::GetCurrentSceneID() {
        return this->scene->GetID();
    }

    Scene *SceneManager::GetCurrentScene() {
        return this->scene;
    }
}

