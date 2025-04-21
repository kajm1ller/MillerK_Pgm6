#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"
#include <iostream>
#include <vector>

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

template <typename T, typename C>
ArrayBHeap<T, C>::~ArrayBHeap() {
	delete[] pArray;
	arraySize = 0;
	heapSize = 0;
	free = 0;

}

template<typename T, typename C>  
void ArrayBHeap<T, C>::buildHeap(const std::vector<T>& input)  
{  
   // Clear the current heap  
   delete[] pArray;  
   heapSize = input.size();  
   arraySize = heapSize;  
   free = heapSize;  

   // Allocate new array  
   pArray = new T[heapSize];  

   // Copy elements from input vector to the array  
   for (int i = 0; i < heapSize; ++i) {  
       pArray[i] = input[i];  
   }  

   // Perform heapify operation  
   for (int i = (heapSize / 2) - 1; i >= 0; --i) {  
       bubbleDown(i);  
   }  
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
	~ArrayBHeap();
	heapSize = 0;
	free = 0;

}

template<typename T, typename C>
bool ArrayBHeap<T, C>::isEmpty() const
{
	if (heapSize == 0) {
		return true;
	}
	return false;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::printHeap() const
{
}

template<typename T, typename C>
int ArrayBHeap<T, C>::getLeftIndex(int index) const
{
	return 2 * index + 1
}

template<typename T, typename C>
int ArrayBHeap<T, C>::getRightIndex(int index) const
{
	return 2 * index + 2;
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
