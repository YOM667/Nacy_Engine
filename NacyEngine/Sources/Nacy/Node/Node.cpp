#include "pch.h"
#include "Node.h"
namespace Engine
{
    Node::Node(std::string name, glm::vec2 position)
        : name(name), position(position)
    {
    }

    std::string Node::GetName()
    {
        return this->name;
    }

    glm::vec2 Node::GetPosition()
    {
        return this->position;
    }

    void Node::addComponent(std::shared_ptr<Component> component)
    {
        this->components.insert(component);
    }

    void Node::addComponentAll(std::set<std::shared_ptr<Component>> components)
    {
        this->components = components;
    }

    std::shared_ptr<Component> Node::GetComponent(std::string id)
    {
        for (const auto& component : components)
        {
            if (component->GetID() == id)
            {
                return component;
            }
        }
        return nullptr;
    }
}