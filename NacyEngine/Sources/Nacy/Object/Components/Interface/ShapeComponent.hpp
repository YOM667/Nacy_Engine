#pragma once
#include "pch.h"
#include "Nacy/Math/Vector.h"
#include "Nacy/Object/Components/Component.hpp"
#include "Nacy/Render/Shape.h"
#include "Nacy/Core/Core.h"
namespace Nacy
{
	enum class NACY_API ShapeType
	{
		ROUND_RECTANGLE = 0, RECTANGLE, CIRCLE, TRIANGLE
	};
	struct ShapeComponent : public Component
	{
		ShapeType shapeType;
		RGBA color;
		float radius;
		NACY_API ShapeComponent(const RGBA& color, ShapeType shapeType = ShapeType::RECTANGLE, float radius = 0.0f) 
			: color(color), shapeType(shapeType) , radius(radius){}

		NACY_API static std::string GetStaticType()
		{
			return "shape";
		}
		NACY_API std::string GetType() override
		{
			return "shape";
		}
	};
}


