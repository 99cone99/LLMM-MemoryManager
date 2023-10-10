#pragma once
class MemoryTracker
{
public:
	MemoryTracker();
	~MemoryTracker();
	size_t GetMemory()
	{
		return totalMemory;
	}

	void AddMemory(size_t memory)
	{
		totalMemory += memory;
	}

	void RemoveMemory(size_t memory)
	{
		totalMemory -= memory;
	}

private:

	size_t totalMemory;

};

