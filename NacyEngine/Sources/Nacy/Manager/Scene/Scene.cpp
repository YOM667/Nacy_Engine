#include "pch.h"
#include "Scene.h"
#include "Nacy/Util/Utilities.h"
#include "Nacy/Object/Components/Game/SpriteComponent.hpp"
#include "Nacy/Object/Components/Game/TransformComponent.hpp"
#include "Nacy/Object/Components/Interface/TextLabelComponent.hpp"
#include "Nacy/Object/Components/Interface/ShapeComponent.hpp"
#include "Nacy/Manager/Input/InputManager.h"
using namespace Utility;
namespace Nacy {
    

    Scene::Scene(int id)
            : id(id), mouseX(0.0f), mouseY(0.0f), initTime(GetNanoTime()),
              screenWidth(0.0f), screenHeight(0.0f), graphic(nullptr) {

    }

    void Scene::AddGameObject(const std::string &name, GameObject *node) {
        this->objects.push_back(std::make_pair(name, node));
    }

    GameObject *Scene::GetGameObject(const std::string &name) {
        for (auto &object: objects) {
            auto obj = object.second;
            if (obj->GetName() == name) {
                return obj;
            }
        }
        return nullptr;
    }
    void Scene::UpdateMouse()
    {
        this->mouseX = InputManager::mouseX;
        this->mouseY = InputManager::mouseY;
    }
    void Scene::Exit() {
        this->Clear();
    }

    void Scene::Clear() {
        this->objects.clear();
    }

    void Scene::SetGraphic(Graphic *graphic) {
        this->graphic = graphic;
    }

    void Scene::SetWindowSize(float width, float height) {
        this->screenWidth = width;
        this->screenHeight = height;
    }

    bool Scene::isHovered(TransformComponent *component) {
        return (mouseX >= component->position.x
                && mouseY >= component->position.y
                && mouseX <= component->position.x + component->size.x
                && mouseY <= component->position.y + component->size.y);
    }

    int Scene::GetID() {
        return this->id;
    }

    void Scene::Render(double delta) {
        this->DrawBackground();
        for (auto &object: this->objects) {
            auto obj = object.second;
            
            if (obj->GetDelayTime() >= GetNanoTime() - this->initTime) {
                continue;
            }
           

            auto transform = obj->GetComponent<TransformComponent>();
            auto sprite = obj->GetComponent<SpriteComponent>();
            auto text = obj->GetComponent<TextLabelComponent>();
            auto shape = obj->GetComponent<ShapeComponent>();
            if (shape != nullptr) {
                switch (shape->shapeType) {
                    case ShapeType::RECTANGLE:

                        Graphic::DrawRoundedRect(transform->position,transform->size
                                                     ,shape->radius, shape->color,1.0f);
                        break;
                    case ShapeType::ROUND_RECTANGLE:
                        Graphic::DrawRect(transform->position,transform->size
                                              ,shape->color,1.0f);
                        break;
                    case ShapeType::CIRCLE:
                        break;
                    case ShapeType::TRIANGLE:
                        break;
                }
            }
            if (sprite != nullptr) {
                switch (sprite->spriteType) {
                    case SpriteType::NORMAL:
                        Graphic::DrawSprite(sprite->texture,transform->position,transform->size
                                                 ,sprite->color);
                        break;
                    case SpriteType::ROUND:
                        Graphic::DrawRoundedSprite(sprite->texture,
                                                        transform->position,transform->size,
                                                        sprite->radius,transform->scale,sprite->color);
                }

            }
            if (text != nullptr) {
                if (text->centered) {
                    Graphic::DrawTextW(text->font,text->text,
                            transform->position,
                            text->color,
                            1.0f
                    );
                } else {
                    Graphic::DrawCenteredText(text->font,
                            text->text,
                            transform->position,
                            text->color,
                            1.0f
                    );
                }

            }
        }
    }
    void Scene::PreInit() {
    }

    void Scene::Init() {

    }

    void Scene::Update(double delta) {
        for (auto& object : this->objects) {
            auto range = GetNanoTime() - initTime;
            auto time = object.second->GetDelayTime();
            if (time >= range) {
                continue;
            }
            object.second->Update(delta);
        }
    }

    void Scene::DrawBackground() {

    }

    void Scene::DrawHUD() {

    }

    void Scene::OnMouseButton(int button) {

    }

    bool Scene::isHovered(const Vector2 &position, const Vector2 &size) {
        return (mouseX >= position.x
        && mouseY >= position.y
        && mouseX <= position.x + size.x
        && mouseY <= position.y + size.y);
    }


}