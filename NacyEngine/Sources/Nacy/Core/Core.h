#pragma once

#include "../Utilities.h"

#define ENABLE_ASSERT

#ifdef NACY_PLATFORM_WINDOW
	#ifdef NACY_BUILD_DLL
		#define NACY_API __declspec(dllexport)
		#define NACY_API_TEMPLATE __declspec(dllexport)
	#else 
		#define NACY_API __declspec(dllimport)
		#define NACY_API_TEMPLATE
	#endif
#else
	#error NACY only support Windows system
#endif

#ifdef ENABLE_ASSERT

	#define Assert(check, message, ...)								  \
	{																  \
		if(!check) { error(message, ##__VA_ARGS__); __debugbreak(); } \
	}                         

#endif // ENABLE_ASSERT
