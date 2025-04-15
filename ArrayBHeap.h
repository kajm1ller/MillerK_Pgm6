#pragma once

#ifndef ARRAY_B_HEAP_H
#define ARRAY_B_HEAP_H
#include "BinaryHeapInterface.h"
template <typename T, typename C>
class ArrayBHeap : public BinaryHeapInterface<T>
{
public:
	ArrayBHeap();
	ArrayBHeap(const ArrayBHeap<T, C>&);
	~ArrayBHeap();
	ArrayBHeap<T, C>& operator=(const ArrayBHeap<T, C>&) {
		return pArray == this->pArray;
	
	};
	void buildHeap(const T*, int);
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
	C comparator; // comparator function; provided by the client and used in
	// bubbleUp and bubbleDown methods
	// private utility/helper methods
	int getLeftIndex(int)const;
	int getRightIndex(int)const;
	int getParentIndex(int)const;
	void bubbleUp(int);
	void bubbleDown(int);
	void resizeArray(int);
};
#endif