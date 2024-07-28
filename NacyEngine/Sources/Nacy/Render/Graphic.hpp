#pragma once
#include "Nacy/Render/Sprite.h"
#include "Nacy/Render/Text.h"
#include "Nacy/Render/Shape.h"
#include "Nacy/Core/Core.h"
namespace Nacy
{
	struct Graphic
	{
		SpriteRenderer* sprite;
		ShapeRenderer* shape;
		FontRenderer* text;


		NACY_API Graphic(SpriteRenderer* sprite, 
			ShapeRenderer* shape, 
			FontRenderer* text)
			: sprite(sprite), shape(shape), text(text) {}
	};

}

