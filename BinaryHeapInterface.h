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



template <typename T> // Consider renaming to CompareString for clarity
struct comparestring {
	// Ensure T is std::string or provide specialization
	bool operator()(const std::string& lhs, const std::string& rhs) const {
		return lhs < rhs; // Use string's built-in comparison
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