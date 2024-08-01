#pragma once
#include <iostream>
#include "Nacy/Object/Components/Component.hpp"
namespace Nacy
{
	struct NACY_API DelayComponent : public Component
	{
		uint64_t delayTime;
		DelayComponent(uint64_t delayTime) : delayTime(delayTime) {}

		static std::string GetStaticType()
		{
			return "delay";
		}
		std::string GetType() override
		{
			return "delay";
		}
	};

}