#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"
#include <iostream>

template <typename T, typename C>
ArrayBHeap<T, C>::ArrayBHeap() {
	pArray = new T*[0];
	arraySize = 0;
	heapSize = 0;
	free = 0;
	comparator = new C(nullptr);
}

template <typename T, typename C>
ArrayBHeap<T, C>::ArrayBHeap(const ArrayBHeap<T, C>&) {
	pArray = this->pArray;
	arraySize = this->arraySize;
	heapSize = this->heapSize;
	free = this->free;
	comparator = this->comparator;
}

// This Shit Fucked Up!

template <typename T, typename C>
ArrayBHeap<T, C>::~ArrayBHeap() {
	delete[] pArray;
	arraySize = 0;
	heapSize = 0;
	free = 0;

}

template<typename T, typename C>
void ArrayBHeap<T, C>::buildHeap(const T*, int)
{

}

template<typename T, typename C>
void ArrayBHeap<T, C>::insert(const T&)
{
}

template<typename T, typename C>
T ArrayBHeap<T, C>::removeMin()
{
	return T();
}

template<typename T, typename C>
void ArrayBHeap<T, C>::empty()
{
}

template<typename T, typename C>
bool ArrayBHeap<T, C>::isEmpty() const
{
	return false;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::printHeap() const
{
}

template<typename T, typename C>
int ArrayBHeap<T, C>::getLeftIndex(int index) const
{
	if (pArray[2 * index + 1] == nullptr) {
		std::cout << "invalid index";
		return 0;
	}
	return pArray[2 * index + 1];
}

template<typename T, typename C>
int ArrayBHeap<T, C>::getRightIndex(int index) const
{
	if (pArray[2 * index + 2] == nullptr) {
		std::cout << "invalid index";
		return 0;
	}
	return pArray[2 * index + 2];
}

template<typename T, typename C>
void ArrayBHeap<T, C>::bubbleUp(int nodeIndex)
{
	int parentIndex;

	while (nodeIndex > 0) {
		parentIndex = (nodeIndex - 1) / 2;
	}

	if (pArray[nodeIndex] <= pArray[parentIndex]) {
		return; 
	} 
	else {
		int temp = pArray[nodeIndex];
		pArray[nodeIndex] = pArray[parentIndex];
		pArray[parentIndex] = temp;
		nodeIndex = parentIndex;
	}
}


template<typename T, typename C>
void ArrayBHeap<T, C>::bubbleDown(int nodeIndex)
{
	int childIndex = 2 * nodeIndex + 1;
	int value = pArray[nodeIndex];

	while (childIndex < heapSize) {
		
		int maxValue = value;
		int maxIndex = -1;
		for (int i = 0; i < 2 && i + childIndex < heapSize; i++) {
			if (pArray[i + childIndex] > maxValue) {
				maxValue = pArray[i + childIndex];
				maxIndex = i + childIndex;
			}
		}

		if (maxValue == value) {
			
			return;
		}

		else {
			
			int temp = pArray[nodeIndex];
			pArray[nodeIndex] = pArray[maxIndex];
			pArray[maxIndex] = temp;

			nodeIndex = maxIndex;
			childIndex = 2 * nodeIndex + 1;
		}
	}
}
