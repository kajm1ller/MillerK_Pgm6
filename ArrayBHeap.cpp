#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"

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
