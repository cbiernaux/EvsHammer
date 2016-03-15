#pragma once

#include <cstdint>
#include <cstddef>

#ifdef WIN32
#define HAMMER_API __declspec(dllexport)
typedef void(__cdecl *HammerEventCallback) (char*, int32_t);
#else
#define HAMMER_API __attribute__((visibility("default")))
typedef void(*HammerEventCallback) (char*, int32_t);
#endif

extern "C"
{
  HAMMER_API char*  GetClipDatabase(int32_t& sizeOfData);

  HAMMER_API void   FreeClipDatabase(char* data);

  HAMMER_API void   FreeClipEvent(char* data);

  HAMMER_API void   RegisterToEvents(HammerEventCallback callback);

  HAMMER_API void   UnregisterFromEvents();
}