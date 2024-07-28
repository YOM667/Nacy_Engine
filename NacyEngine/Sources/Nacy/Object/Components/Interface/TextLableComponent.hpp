#pragma once
#include "Nacy/Object/Components/Component.hpp"
#include "Nacy/Math/Vector.h"
namespace Nacy
{
	struct TextLableComponent : public Component
	{
		bool centered;
		RGBA color;
		const char* text;
		const char* font;

		NACY_API explicit TextLableComponent(const char* text,const char* font, RGBA color = RGBA(255.0f, 255.0f, 255.0f, 255.0f), bool centered = false)
			: text(text), font(font), color(color), centered(centered) {}

		NACY_API static std::string GetStaticType()
		{
			return "lable";
		}
		NACY_API std::string GetType() override
		{
			return "lable";
		}
	};

}


