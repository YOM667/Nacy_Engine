#include "pch.h"
#include "Scene.h"


namespace Engine
{
	void init()
	{

	}
	Scene::Scene()
	{

	}
	void Scene::addNode(std::string name, Node node)
	{
		this->nodes.insert(make_pair(name,node));
	}

	void Scene::removeNode(std::string name)
	{

	}

	void Scene::render()
	{

	}
}