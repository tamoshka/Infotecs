#pragma once

#ifdef INFOTECSLIBRARY_EXPORTS
#define INFOTECSLIBRARY_API __declspec(dllexport)
#else
#define INFOTECSLIBRARY_API __declspec(dllimport)
#endif


extern "C" INFOTECSLIBRARY_API void FunctionOne(string message);

extern "C" INFOTECSLIBRARY_API int FunctionTwo(string message);

extern "C" INFOTECSLIBRARY_API bool FunctionThree(int data);