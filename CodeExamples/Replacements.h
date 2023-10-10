#pragma once
#include <iostream>

#include "Structs.h"

void* operator new (size_t size, MemoryTracker* pTracker);
//void* operator new (size_t size);
void operator delete (void* pMem);