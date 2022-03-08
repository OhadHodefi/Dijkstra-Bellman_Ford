#pragma once
#include <string.h>
#include "PriorityQueue.h"

#define INITARRAY -1

typedef struct {
	bool deleteVertex;//Returns whether the vertex has been deleted or not
	float* weight;
}NodeForArray;

class PriorityQueueWithArray:public PriorityQueue
{
private:
	NodeForArray* arr;
	int numOfVertex;

public:
	PriorityQueueWithArray();//constructor
	PriorityQueueWithArray(int sizeOfArr, float* arr);//constructor who gets an array and its size
	~PriorityQueueWithArray();//disconstructor
	
	virtual void Build(float* arr, int size) override;//Builds the array
	int Min();//Returns the minimum value
	virtual int DeleteMin() throw(const char*)override;//delete and returns the minimum value
	virtual bool IsEmpty() override;//Returns true if the queue is empty, otherwise false
	virtual void DecreaseKey(int place, float newKey) override;//Decreases the value of the hookpoint in place 'place'
};
