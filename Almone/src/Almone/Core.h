#pragma once


#ifdef ALM_PLATFORM_WINDOWS
	#ifdef ALM_BUILD_DLL
		#define ALM_API __declspec(dllexport)
	#else
		#define ALM_API __declspec(dllimport)
	#endif
#else
	#error Almone only supports Windows OS!
#endif 