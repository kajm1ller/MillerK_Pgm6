#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"
#include "Sumo.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility> // for std::swap


template <typename T, typename C>
ArrayBHeap<T, C>::ArrayBHeap() {
	pArray = new T[0];
	arraySize = 0;
	heapSize = 0;
	free = 0;
	comparator = C();
}

template <typename T, typename C>
ArrayBHeap<T, C>::ArrayBHeap(const ArrayBHeap<T, C>& initArray) { 
	pArray = initArray.pArray;
	arraySize = initArray.arraySize;
	heapSize = initArray.heapSize;
	free = initArray.free;
	comparator = initArray.comparator;
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
	// Ensure sufficient capacity - start with input size or a bit more
	arraySize = heapSize > 0 ? heapSize : 10; // Start with input size or a default
	free = heapSize;

	// Allocate new array
	pArray = new T[arraySize]; // Use arraySize for allocation

	// Copy elements from input vector to the array
	for (int i = 0; i < heapSize; ++i) {
		pArray[i] = input.at(i);
	}

	// Perform heapify operation using bubbleDown
	// Start from the last non-leaf node and go up to the root
	for (int i = (heapSize / 2) - 1; i >= 0; --i) {
		bubbleDown(i); 
	}
}

template <typename T, typename C>
void ArrayBHeap<T, C>::heapify(T* arr, int n, int i) {
	int smallest = i; // Index of the smallest element found so far (parent initially)
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// Check left child: if it exists and is smaller than the current smallest
	// Use the comparator: comparator(child, current_smallest) returns true if child is "smaller"
	if (left < n && comparator(arr[left], arr[smallest])) {
		smallest = left;
	}

	// Check right child: if it exists and is smaller than the current smallest
	if (right < n && comparator(arr[right], arr[smallest])) {
		smallest = right;
	}

	// If the smallest element is not the root (parent)
	if (smallest != i) {
		// Swap the parent with the smallest child
		std::swap(arr[i], arr[smallest]);

		// Recursively heapify the affected sub-tree (where the original parent moved to)
		heapify(arr, n, smallest);
	}
}

template<typename T, typename C>
void ArrayBHeap<T, C>::insert(const T& x)
{
	// If the array is full (heapSize reaches arraySize)
	if (heapSize == arraySize) {
		// Resize: Double the capacity or add a fixed amount
		int newCapacity = (arraySize == 0) ? 10 : arraySize * 2; // Handle initial size 0
		resizeArray(newCapacity);
		
	}

	pArray[heapSize] = x; // Insert at the current heapSize index

	// Bubble up the new element to its correct position
	bubbleUp(heapSize);

	// Increment the heap size
	heapSize++;
}

template<typename T, typename C>
T ArrayBHeap<T, C>::removeMin()
{
	if (isEmpty()) {
	
		throw std::out_of_range("Heap is empty, cannot remove minimum.");
	}

	T minElement = pArray[0];
	pArray[0] = pArray[heapSize - 1];
	heapSize--;
	
	if (heapSize > 0) { 
		bubbleDown(0);
	}

	return minElement;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::empty()
{
	
	delete[] pArray; // Properly clear the heap
	pArray = nullptr; // Avoid dangling pointer
	heapSize = 0;
	arraySize = 0;
	free = 0;
}

template<typename T, typename C>
bool ArrayBHeap<T, C>::isEmpty() const // self explanatory
{
	if (heapSize == 0) {
		return true;
	}
	return false;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::printHeap() const
{
	if (heapSize == 0) {
		std::cout << "Heap Is Empty" << std::endl;
	}
	else {
		for (int i = 0; i < heapSize; ++i) {
			std::cout << pArray[i] << " ";
		}
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

// 6. Fix getParentIndex
template<typename T, typename C>
int ArrayBHeap<T, C>::getParentIndex(int index) const
{
	return (index - 1) / 2;
}

template<typename T, typename C>
void ArrayBHeap<T, C>::bubbleUp(int nodeIndex)
{
	int parentIndex;
	// Loop while the node is not the root
	while (nodeIndex > 0) {
		parentIndex = (nodeIndex - 1) / 2; // Calculate parent index

		// Use the comparator: If child is smaller than parent (higher priority for min-heap)
		if (comparator(pArray[nodeIndex], pArray[parentIndex])) {
			// Swap child and parent
			std::swap(pArray[nodeIndex], pArray[parentIndex]);
			// Move up to the parent's index
			nodeIndex = parentIndex;
		}
		else {
			
			return;
		}
	}
}

template<typename T, typename C>
void ArrayBHeap<T, C>::bubbleDown(int nodeIndex)
{
	int leftChildIndex;
	int rightChildIndex;
	int targetIndex; // Index of the child to potentially swap with

	while (true) { // Loop until node is in correct position
		leftChildIndex = getLeftIndex(nodeIndex);
		rightChildIndex = getRightIndex(nodeIndex);
		targetIndex = nodeIndex; // Assume parent is smallest initially

		// Check left child: if exists and is smaller than current target
		if (leftChildIndex < heapSize && comparator(pArray[leftChildIndex], pArray[targetIndex])) {
			targetIndex = leftChildIndex;
		}

		// Check right child: if exists and is smaller than current target
		if (rightChildIndex < heapSize && comparator(pArray[rightChildIndex], pArray[targetIndex])) {
			targetIndex = rightChildIndex;
		}

		// If the smallest element is one of the children, swap and continue down
		if (targetIndex != nodeIndex) {
			std::swap(pArray[nodeIndex], pArray[targetIndex]);
			nodeIndex = targetIndex; // Move down to the child's position
		}
		else {
			// Node is smaller than both children (or has no children), heap property holds
			break; 
		}
	}
}

template<typename T, typename C>
void ArrayBHeap<T, C>::resizeArray(int newCapacity) // Pass the desired new capacity
{
	if (newCapacity <= arraySize) return; // Only resize if increasing capacity

	T* newArray = new T[newCapacity];
	// Copy existing elements up to heapSize
	for (int i = 0; i < heapSize; i++) {
		newArray[i] = pArray[i];
	}
	delete[] pArray;
	pArray = newArray;
	arraySize = newCapacity; // Update arraySize to the new capacity
}

template class ArrayBHeap<int, compareint<int>>;
template class ArrayBHeap<std::string, comparestring<std::string>>;
template class ArrayBHeap<sumo, compareobj<sumo>>;

