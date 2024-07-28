#pragma once
#include "pch.h"
#include "Nacy/Object/Components/Component.hpp"
#include "Nacy/Core/Core.h"
#include "Nacy/Math/Vector.h"
namespace Nacy
{
	struct TransformComponent : public Component
	{
        Vector2 position;
        Vector2 size;
        double scale;
        double rotation;

        NACY_API explicit TransformComponent(Vector2 position = Vector2::create(0.0f,0.0f),
            Vector2 size = Vector2::create(1.0f, 1.0f),
            double scale = 1.0f,
            double rotation = 0.0) 
            : position(position),
            size(size),
            scale(scale),
            rotation(rotation) {}
        NACY_API static std::string GetStaticType()
        {
            return "transform";
        }
        NACY_API std::string GetType() override
        {
            return "transform";
        }
	};
}

