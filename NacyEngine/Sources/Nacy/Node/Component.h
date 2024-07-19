#pragma once
#include "Nacy/Core/Core.h"
namespace Engine
{
	class NACY_API Component
	{
	public:
		Component(std::string name);
		virtual std::string GetID();
		std::string GetName();
	private:
		std::string name;
	};

}

