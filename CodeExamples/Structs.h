#pragma once
#include "MemoryTracker.h"

struct Header
{
	int size; // Stores the size of the main allocated section
	int eCheck; // Used to make sure the data has not been overwritten
	MemoryTracker* pTracker; // Used to track the amount of data used overall
	Header* pNext; // Used to point the next memory allocation
	Header* pPrev;// Used to point the previous memory allocation
};

struct Footer
{
	int reserved; // Used later?
	int eCheck;
};
