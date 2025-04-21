#pragma once

#ifndef ARRAY_B_HEAP_H
#define ARRAY_B_HEAP_H
#include "BinaryHeapInterface.h"
#include <vector>
#include <stdexcept>

template <typename T, typename C>
class ArrayBHeap : public BinaryHeapInterface<T>
{
public:
	ArrayBHeap();
	ArrayBHeap(const ArrayBHeap<T, C>& todd);
	~ArrayBHeap();
    ArrayBHeap<T, C>& operator=(const ArrayBHeap<T, C>& other) {  
       if (this != &other) { // Check for self-assignment  
           // Free existing resources  
           delete[] pArray;  

           // Copy data from the other object  
           arraySize = other.arraySize;  
           heapSize = other.heapSize;  
           free = other.free;  
           comparator = other.comparator;  

           // Allocate new memory and copy the array  
           pArray = new T[arraySize];  
           if (heapSize > arraySize) {  
               throw std::out_of_range("Heap size exceeds array size during assignment.");  
           }  
           for (int i = 0; i < heapSize; ++i) {  
               pArray[i] = other.pArray[i];  
           }  
       }  
       return *this; // Return a reference to the current object  
    }
	void buildHeap(const std::vector<T> input);
	void insert(const T&) override;
	T removeMin() override;
	void empty() override;
	bool isEmpty()const override;
	void printHeap()const;
private:
	// data elements
	T* pArray; // heap storage array, dynamically allocated
	int arraySize; // maximum size heap that array can accommodate
	int heapSize; // actual number of elements on the heap
	int free; // next spot available for an item
	C comparator; // comparator function; provided by the client and used in bubbleUp and bubbleDown methods

	// private utility/helper methods
	int getLeftIndex(int index)const;
	int getRightIndex(int index)const;
	int getParentIndex(int index)const;
	void bubbleUp(int nodeIndex);
	void bubbleDown(int nodeIndex);
	void resizeArray(int);
};
#endif