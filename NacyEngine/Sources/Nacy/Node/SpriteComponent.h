#pragma once
#include "Component.h"
#include "Nacy/Core/Core.h"
namespace Engine
{
	class NACY_API SpriteComponent : public Component
	{
	public:
		SpriteComponent(std::string mName);

		std::string GetID() override;
	};
}


