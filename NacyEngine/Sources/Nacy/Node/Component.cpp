#include "pch.h"
#include "Component.h"

namespace Engine
{
	Component::Component(std::string name) : name(name)
	{

	}
	std::string Component::GetName()
	{
		return this->name;
	}

	std::string Component::GetID()
	{
		return "component";
	}

}
