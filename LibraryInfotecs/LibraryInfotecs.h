#pragma once

#define LIBRARYINFOTECS_API 

extern "C" LIBRARYINFOTECS_API void FunctionOne(std::string& message);

extern "C" LIBRARYINFOTECS_API int FunctionTwo(std::string message);

extern "C" LIBRARYINFOTECS_API bool FunctionThree(int data);