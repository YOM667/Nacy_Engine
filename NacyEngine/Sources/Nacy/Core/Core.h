#pragma once
#include <cstdio>

#define ENABLE_ASSERT

#ifdef NACY_PLATFORM_WINDOW
	#ifdef NACY_BUILD_DLL
		#define NACY_API __declspec(dllexport)
	#else 
		#define NACY_API __declspec(dllimport)
	#endif
#else
	#error NACY only support Windows system
#endif

#ifdef ENABLE_ASSERT

	#define Assert(check, message, ...)								  \
	{																  \
		if(!check) { printf(message, ##__VA_ARGS__); __debugbreak(); } \
	}                         

#endif // ENABLE_ASSERT