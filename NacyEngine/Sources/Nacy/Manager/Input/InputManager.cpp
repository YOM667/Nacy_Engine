#include "pch.h"
#include "InputManager.h"

namespace Nacy
{
	std::map<const char*, KeyBinding> InputManager::keybindingMap = std::map<const char*, KeyBinding>() = {};


	void InputManager::RegisterKeyBinding(const char* name, const KeyBinding& keyBinding)
	{
		keybindingMap[name] = keyBinding;
	}
	void InputManager::KeyAction(int keyCode, const KeyActionType& type)
	{
		for (auto& key : keybindingMap)
		{
			auto& keyBinding = key.second;
			if (keyBinding.keyCode == -1)
			{
				keyBinding.func(type);
			}
			else if (keyCode == keyBinding.keyCode)
			{
				keyBinding.func(type);
			}

		}
	}
}

