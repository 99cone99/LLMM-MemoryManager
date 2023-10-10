#include "BaseObject.h"


#include <iostream>

using namespace std;

void * BaseObject::operator new(size_t size, MemoryTracker* s_pTracker)
{
	std::cout << "baseobject new is being called\n";
	return::operator new(size, s_pTracker);
}

void BaseObject::operator delete(void* p, size_t size)
{
	std::cout << "baseobject delete is being called\n";
	return::operator delete(p);
}

BaseObject::BaseObject()
{
	cout << "BaseObject :: constructor \n";
}

BaseObject::~BaseObject()
{
	cout << "BaseObject :: destructor \n";
}

void BaseObject::aMethod()
{
	cout << "BaseObject :: aMethod \n";
}