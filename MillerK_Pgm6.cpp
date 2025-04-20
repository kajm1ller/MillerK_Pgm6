#include <iostream>
#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"
#include <iostream>
#include <vector>

int main() {


	ArrayBHeap<int, compareint<int>> heap;
	std::vector<int> v = { 13, 42, 15, 6, 19, 7, 57 };
	heap.buildHeap(v);
	heap.printHeap();
	std::cout << "Inserting 4" << std::endl;
	heap.insert(4);
	heap.printHeap();
	std::cout << "Inserting 17" << std::endl;
	heap.insert(17);
	heap.printHeap();
	std::cout << "Inserting 1" << std::endl;
	heap.insert(1);
	heap.printHeap();
	int min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();
	min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();

	min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();
	min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();
	min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();
	min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();
	min = heap.removeMin();
	std::cout << "Removing min value: " << min << std::endl;
	heap.printHeap();
	std::cout << "Rebuild new heap" << std::endl;
	heap.buildHeap(v);
	heap.printHeap();
	std::cout << "Empty heap" << std::endl;
	heap.empty();
	heap.printHeap();


	return 0;
}