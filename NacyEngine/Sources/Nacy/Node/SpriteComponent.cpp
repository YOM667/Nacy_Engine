#include "pch.h"
#include "SpriteComponent.h"

namespace Engine
{
	SpriteComponent::SpriteComponent(std::string mName) : Component(mName)
	{

	}
	std::string SpriteComponent::GetID()
	{
		return "sprite";
	}
}
