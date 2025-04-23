#pragma once

#include <string>

// Add the following comparator class to define compareint  
template <typename T>  
struct compareint {  
   bool operator()(const T& lhs, const T& rhs) const {  
       return lhs < rhs; // Min-heap comparison  
   }  
};

template <typename T>
struct comparedouble {
	bool operator()(const T& lhs, const T& rhs) const {
		return lhs < rhs; // Min-heap comparison
	}
};

template <typename T> // I keep getting fucking linker errors because of this
struct comparestring {
	bool operator()(const T& lhs, const T& rhs) const {
		return sizeof(lhs) < sizeof(rhs);
	}
};
#ifndef BINARY_HEAP_INTERFACE_H
#define BINARY_HEAP_INTERFACE_H

template <typename T>
class BinaryHeapInterface
{
public:
	virtual void insert(const T&) = 0;
	virtual T removeMin() = 0; // lowest value is highest priority
	virtual void empty() = 0;
	virtual bool isEmpty()const = 0;
};
#endif //BINARY_HEAP_INTERFACE_H