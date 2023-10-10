#include "Replacements.h"

void* operator new (size_t size, MemoryTracker* pTracker)
{
	std::cout << "new is being called\n";

	size_t nRequestedByted = size + sizeof(Header) + sizeof(Footer); // Size of requested + header + footer
	char* pMem = (char*)malloc(nRequestedByted);
	Header* pHeader = (Header*)pMem; // Set header pointer to the start of allocated memory

	pHeader->size = size; // Set the headers "size" to the size of the allocated data

	void* pFooterAddr = pMem + sizeof(Header) + size; // Set a pointer to the footer
	Footer* pFooter = (Footer*)pFooterAddr; // Cast the footer void* pointer

	pHeader->eCheck = 0xDEADC0DE; // Sets the overwrite check
	pFooter->eCheck = 0xDEADBEEF;
	pHeader->pTracker = pTracker;

	void* pStartMemBlock = pMem + sizeof(Header);
	return pStartMemBlock;
}

/*void* operator new (size_t size)
{
	std::cout << "new is being called\n";

	size_t nRequestedByted = size + sizeof(Header) + sizeof(Footer); // Size of requested + header + footer
	char* pMem = (char*)malloc(nRequestedByted);
	Header* pHeader = (Header*)pMem; // Set header pointer to the start of allocated memory

	pHeader->size = size; // Set the headers "size" to the size of the allocated data

	void* pFooterAddr = pMem + sizeof(Header) + size; // Set a pointer to the footer
	Footer* pFooter = (Footer*)pFooterAddr; // Cast the footer void* pointer

	pHeader->eCheck = 0xDEADC0DE; // Sets the overwrite check
	pFooter->eCheck = 0xDEADBEEF;

	void* pStartMemBlock = pMem + sizeof(Header);
	return pStartMemBlock;
}*/

void operator delete (void* pMem)
{
	std::cout << "delete is being called\n";
	Header* pHeader = (Header*)((char*)pMem - sizeof(Header));
	Footer* pFooter = (Footer*)((char*)pMem + pHeader->size);

	if (pHeader->eCheck == 0xDEADC0DE && pFooter->eCheck == 0xDEADBEEF)
		free(pHeader);
	else
		std::cout << "ERROR: Memory has been overwritten\n";
}