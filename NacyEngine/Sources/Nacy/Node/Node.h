#pragma once
#include "Component.h"
#include "Nacy/Core/Core.h"
namespace Engine
{
	class Node
	{
	public:
		NACY_API Node(std::string name, glm::vec2 position);

		NACY_API std::string GetName();

		NACY_API glm::vec2 GetPosition();

		NACY_API std::shared_ptr<Component> GetComponent(std::string id);

		NACY_API void addComponent(std::shared_ptr<Component> component);
		NACY_API void addComponentAll(std::set<std::shared_ptr<Component>> components);
	private:
		std::set<std::shared_ptr<Component>> components;

		std::vector<Node> extendNodes;

		glm::vec2 position;

		std::string name;
	};
}