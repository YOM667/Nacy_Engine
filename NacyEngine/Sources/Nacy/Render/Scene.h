#pragma once

#include "Nacy/Node/Node.h"
namespace Engine
{
	class NACY_API Scene
	{
	public:

		Scene();
		virtual void init() {};

		void addNode(std::string name, Node node);
		void removeNode(std::string name);
	private:
		void render();
		std::map<std::string, Node> nodes;
	};


}
