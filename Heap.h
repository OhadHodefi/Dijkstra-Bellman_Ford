#pragma once
#include <cstdio>
#include "PriorityQueue.h"

using namespace std;

#define INITARRAY -1

typedef struct {
	int targetVertex;
	float* weight;
}NodeForHeap;

class Heap :public PriorityQueue
{
	
private:

	int* IndexArry;
	NodeForHeap* data;
	float maxSize;
	int heapSize;
	int allocated;
	static int Left(int node);//Returns left child
	static int Right(int node);//Returns right child
	static int Parent(int node);//Returns parent
	void Swap(NodeForHeap* n1, NodeForHeap* n2);//Makes a switch between n1 to n2
	void FixHeap(int node);

public:
	Heap();//constructor
	~Heap();//disconstructor
	virtual void Build(float* arr, int size) override;//This method builds the heap (with Floyd)
	int Min();//Returns the minimum value of the heap
	virtual int DeleteMin() throw(const char*) override;//Deletes and returns the minimum value of the heap
	void UpdateKey(int index);//Updating the key
	virtual bool IsEmpty() override;//Returns true if the heap is empty otherwise false
	virtual void DecreaseKey(int place, float newKey) override;//Updates the weight of a vertex instead of the 'place'
};