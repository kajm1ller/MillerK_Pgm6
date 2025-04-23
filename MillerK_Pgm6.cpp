#include <iostream>
#include "BinaryHeapInterface.h"
#include "ArrayBHeap.h"
#include "Sumo.h"
#include <vector>
#include <string>


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

	std::vector<std::string> sv = { "snake", "dog", "elephant", "rabbit", "bear" };
	ArrayBHeap<std::string, comparestring<std::string>> stringHeap;
	stringHeap.buildHeap(sv);
	std::cout << "-------------------------" << std::endl;
	std::cout << "Current Array Size: " << stringHeap.getArraySize() << std::endl;
	std::cout << "Current Heap Size: " << stringHeap.getHeapSize() << std::endl;

	sumo s1, s2, s3;
	s1.setName("Hakuho");
	s1.setRank("Yokozuna");
	s1.setWins(22);
	s2.setName("Toshimitsu");
	s2.setRank("Yokozuna");
	s2.setWins(14);
	s3.setName("Musashimaru");
	s3.setRank("Yokozuna");
	s3.setWins(36);
	std::vector<sumo> vsumo = { s1, s2, s3 };
	ArrayBHeap<sumo, compareobj<sumo>> sumoheap;
	sumoheap.buildHeap(vsumo);
	sumoheap.printHeap();




	return 0;
}