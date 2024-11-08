// CodeExamples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BaseObject.h"
#include "Replacements.h"

using namespace std;

void example1(MemoryTracker* Tracker);
void example2(MemoryTracker* Tracker);
void example3(MemoryTracker* Tracker);
void example4(MemoryTracker* Tracker);

int main()
{
    MemoryTracker* Tracker = new MemoryTracker();

    cout << "Here are some memory tests\n\n";
    
    cout << "Example1\n\n";
    // Pointer Basics
    example1(Tracker);
    
    cout << "Example2\n\n";
    // Array Basics
    example2(Tracker);

    cout << "\nCurrent total memory used is " << Tracker->GetMemory() << "\n\n";

    cout << "Example3\n\n";
    // new and delete
    example3(Tracker);

    cout << "\nCurrent total memory used is " << Tracker->GetMemory() << "\n\n";

    cout << "Example4\n\n";
    // new and delete with arrays and memeory chunks
    example4(Tracker);

    cout << "\nCurrent total memory used is " << Tracker->GetMemory() << "\n\n";

}

// Pointer Basics
void example1(MemoryTracker* Tracker) {
    
    float height = 1.2f;
    char ch = 'x';

    // print the values
    cout << height << ", " << ch << endl;

    // create pointers to each
    float* pheight = &height;
    char* pch = &ch;

    // print the address values
    // we need to cast pch to a void * because cout treats it as a string (pch *does* contain the address of 'ch')
    cout << pheight << ", " << (void*)pch << endl;
   
    // we can change values using pointers by dereferencing like so:
    *pheight = 0.3f;
    *pch = 'c';
    cout << height << ", " << ch << endl << endl;
}

// Array Basics
void example2(MemoryTracker* Tracker) {
    float* pf = nullptr;

    // a simple 1D array
    float floatarray[] = { 1,2,3,4,5,6,7 };

    float floatarray2[16] = { 0 }; // this will set each value of the array to 0

    // getting the size of the array
    int sizeArrayBytes = sizeof(floatarray);
    cout << sizeArrayBytes << endl; // what will this print out?

    // sizeArray is in bytes! a float is (usually) 4 bytes
    int sizeElement = sizeof(float);
    int sizeArray = sizeArrayBytes / sizeElement;
    cout << sizeArray << endl;

    // using a pointer to reference array
    pf = floatarray; 

    cout << *pf << endl;

    pf++;

    cout << *pf << endl << endl;
}

void example3(MemoryTracker* Tracker) {

    // C style memory allocation - malloc allocates in bytes
    int* int1 = (int*)malloc(sizeof(int)); 
    *int1 = 1;
    free(int1);

    // C++ style memory allocation
    int* int2 = new(Tracker) int;
    *int2 = 1;
    
    delete int2;

    cout << "\ncreate & free object with new / delete\n";
    BaseObject* bArrWithNew = new(Tracker) BaseObject();
    bArrWithNew->aMethod();
    delete bArrWithNew;

    cout << "\ncreate and free object with malloc / free \n";
    BaseObject* bArrWithMalloc = (BaseObject*)malloc(sizeof(BaseObject));
    bArrWithMalloc->aMethod();
    free(bArrWithMalloc);
    cout << endl;
}

void example4(MemoryTracker* Tracker) {
    // C style memory allocation - malloc allocates in bytes
    int* intarray1 = (int*)malloc(sizeof(int) * 2);
    intarray1[0] = 1;
    intarray1[1] = 2;
    free(intarray1);

    // C++ style memory allocation
    int* intarray2 = new(Tracker) int[2];
    intarray2[0] = 1;
    intarray2[1] = 2;
    delete[] intarray2; // note we need to delete with the brackets (why, do you think?)

    BaseObject* bArrWithNew = new(Tracker) BaseObject[2];
    delete[] bArrWithNew; 

    // This MAY work with some compilers (but expect a crash on VS)
    /*
    BaseObject* bArrWithNew2 = new BaseObject[2];
    delete bArrWithNew2;  // <<< note no [] after the delete
    */
}

