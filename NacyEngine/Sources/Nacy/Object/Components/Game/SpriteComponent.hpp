#pragma once
#include "Nacy/Math/Vector.h"
#include "Nacy/Object/Components/Component.hpp"
#include "Nacy/Core/Core.h"
#include "Nacy/Render/Texture.h"
namespace Nacy
{
	struct SpriteComponent : public Component
	{
		RGBA color;
		Texture2D texture;
		int zIndex;
		NACY_API explicit SpriteComponent(Texture2D& texture, RGBA color = RGBA(255.0f,255.0f,255.0f,255.0f), int zIndex = 0)
			: texture(texture), zIndex(zIndex) , color(color) {}
		NACY_API static std::string GetStaticType()
		{
			return "sprite";
		}
		NACY_API std::string GetType() override
		{
			return "sprite";
		}
	};

}

