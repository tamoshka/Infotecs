#pragma once

#ifdef LIBRARYINFOTECS_EXPORTS
#define LIBRARYINFOTECS_API __declspec(dllexport)
#else
#define LIBRARYINFOTECS_API __declspec(dllimport)
#endif


extern "C" LIBRARYINFOTECS_API void FunctionOne(std::string& message);

extern "C" LIBRARYINFOTECS_API int FunctionTwo(std::string message);

extern "C" LIBRARYINFOTECS_API bool FunctionThree(int data);