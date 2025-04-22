#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"
#include <iostream>
#include <vector>

template <typename T, typename C>
ArrayBHeap<T, C>::ArrayBHeap() {
	pArray = new T[0];
	arraySize = 0;
	heapSize = 0;
	free = 0;
	comparator = C();
}

template <typename T, typename C>
ArrayBHeap<T, C>::ArrayBHeap(const ArrayBHeap<T, C>& todd) {
	pArray = todd.pArray;
	arraySize = todd.arraySize;
	heapSize = todd.heapSize;
	free = todd.free;
	comparator = todd.comparator;
}

template <typename T, typename C>
ArrayBHeap<T, C>::~ArrayBHeap() {
	delete[] pArray;
	arraySize = 0;
	heapSize = 0;
	free = 0;

}

template<typename T, typename C>
void ArrayBHeap<T, C>::buildHeap(const std::vector<T> input)
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
		pArray[i] = input.at(i);
	}


	// Perform heapify operation  
	for (int i = (heapSize / 2) - 1; i >= 0; --i) {
		heapify(pArray, heapSize, i);
	}
}



template <typename T, typename C>
void ArrayBHeap<T, C>::heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

template<typename T, typename C>
void ArrayBHeap<T, C>::insert(const T& x)
{
	if (arraySize == heapSize) {
		resizeArray(arraySize * 2);
		arraySize = arraySize * 2;
	}
	
		pArray[free] = x;
		free++;
		heapSize++;
		bubbleUp(free - 1);

}

template<typename T, typename C>
T ArrayBHeap<T, C>::removeMin()
{
	int min = pArray[heapSize - 1];
	pArray[heapSize - 1] = 0;
	free--;
	heapSize--;
	return min;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::empty()
{
	// Properly clear the heap
	delete[] pArray;
	pArray = nullptr; // Avoid dangling pointer
	heapSize = 0;
	arraySize = 0;
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
	for (int i = 0; i < heapSize; ++i) {
		std::cout << pArray[i] << " ";
	}
	std::cout << std::endl;
}


template<typename T, typename C>
int ArrayBHeap<T, C>::getLeftIndex(int index) const
{
	return 2 * index + 1;
}

template<typename T, typename C>
int ArrayBHeap<T, C>::getRightIndex(int index) const
{
	return 2 * index + 2;
}

template<typename T, typename C>
int ArrayBHeap<T, C>::getParentIndex(int index) const
{
	return index / 2;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::bubbleUp(int nodeIndex)
{
	int parentIndex = 0;

	while (nodeIndex < 0) { // changed this from greater to less than. Don't know what consequences this will bring.		parentIndex = (nodeIndex - 1) / 2;
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

template<typename T, typename C>
void ArrayBHeap<T, C>::resizeArray(int)
{
	T* newArray = new T[arraySize * 2];
	for (int i = 0; i < arraySize; i++) {
		newArray[i] = pArray[i];
	}
	delete[] pArray;
	pArray = newArray;
	arraySize *= 2;

}

template class ArrayBHeap<int, compareint<int>>;
