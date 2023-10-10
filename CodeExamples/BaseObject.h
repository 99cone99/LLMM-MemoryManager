#pragma once

#include "Replacements.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

public:
	void aMethod();
	static void* operator new(size_t size, MemoryTracker* s_pTracker);
	static void operator delete(void* p, size_t size);

};

