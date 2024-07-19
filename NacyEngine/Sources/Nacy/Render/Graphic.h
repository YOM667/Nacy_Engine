#pragma once
#include <memory>
#include "Nacy/Manager/Sprite.h"
#include "Nacy/Manager/Text.h"
#include "Nacy/Manager/Shape.h"
#include "Nacy/Core/Core.h"
namespace Engine
{
	struct Graphic
	{
		NACY_API Graphic(std::shared_ptr<SpriteRenderer> sprite, std::shared_ptr<ShapeRenderer> shape, std::shared_ptr<FontRenderer> text);
		std::shared_ptr<SpriteRenderer> sprite;
		std::shared_ptr<ShapeRenderer> shape;
		std::shared_ptr<FontRenderer> text;
	};

}

