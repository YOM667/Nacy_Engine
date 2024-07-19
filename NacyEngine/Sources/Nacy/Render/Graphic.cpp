#include "pch.h"
#include "Graphic.h"
namespace Engine
{

	Graphic::Graphic(std::shared_ptr<SpriteRenderer> sprite, std::shared_ptr<ShapeRenderer> shape, std::shared_ptr<FontRenderer> text)
		: sprite(sprite), shape(shape), text(text)
	{
	}
}

