#pragma once
#include "Nacy/Core/Core.h"

namespace Nacy
{
	enum class NACY_API KeyConflit
	{
		IN_SCENE, IN_GAME, IN_ANYTHING
	};
	enum class NACY_API KeyActionType
	{
		KEY_PRESSED, KEY_RELESED
	};
	struct KeyBinding
	{
		using KeyActionFunc = std::function<void(KeyActionType)>;

		int keyCode;
		KeyConflit conflit;
		KeyActionFunc func;
		NACY_API KeyBinding() : keyCode(0), conflit(KeyConflit::IN_ANYTHING), func(nullptr) {}
		NACY_API KeyBinding(int keyCode,const KeyConflit& conflit, const KeyActionFunc& func)
			: keyCode(keyCode), conflit(conflit), func(func){}
	};
	class InputManager
	{
	private:
		static std::map<const char*, KeyBinding> keybindingMap;
	public:
		NACY_API static void RegisterKeyBinding(const char* name, const KeyBinding& keyBinding);
		NACY_API static void KeyAction(int keyCode, const KeyActionType& type);


	};
}

