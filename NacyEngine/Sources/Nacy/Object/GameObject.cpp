#include "pch.h"

#include "GameObject.h"
#include "Nacy/Object/Components/Game/TransformComponent.hpp"

namespace Nacy {
    GameObject::GameObject(std::string name)
            : name(name), visiable(true), delayTime(0) {
        this->AddComponent(new TransformComponent());
    }

    std::string GameObject::GetName() {
        return this->name;
    }

    void GameObject::AddComponent(Component *component) {
        this->components.push_back(component);
    }

    bool GameObject::GetVisible() {
        return this->visiable;
    }

    void GameObject::SetVisible(bool visible = true) {
        this->visiable = visible;
    }
    void GameObject::SetDelayTime(long long delayTime) {
        this->delayTime = delayTime;
    }
    long long GameObject::GetDelayTime() {
        return this->delayTime;
    }
    void GameObject::Render() {

    }

    void GameObject::Update(double delta) {

    }
}