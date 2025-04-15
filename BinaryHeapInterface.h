#pragma once
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