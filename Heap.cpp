#include "Heap.h"


Heap::Heap()
{
	this->IndexArry=nullptr;
	this->data=nullptr;
	allocated = 0;
}

void Heap::Build(float* arr, int size)
{
	this->IndexArry = new int[size];
	for(int i=0;i<size;i++)//Initializes the array that saves the indexes to the heap
	{
		this->IndexArry[i] = i;
	}

	data = new NodeForHeap[size];

	for (int i = 0; i < size; i++)
	{
		data[i].targetVertex = i;
		data[i].weight = arr + i;
	}
	
	maxSize = size;
	heapSize = maxSize;
	allocated = 1;
	for (int i = size / 2 - 1; i >= 0; i--)
		FixHeap(i);

}
Heap::~Heap()
{
	if (allocated)
	{
		delete[] data;
		delete[] IndexArry;
	}
	this->data = nullptr;
	this->IndexArry = nullptr;
}

int Heap::Parent(int node)
{
	return (node - 1) / 2;
}

int Heap::Left(int node)
{
	return (2 * node + 1);
}

int Heap::Right(int node)
{
	return (2 * node + 2);
}

void Heap::Swap(NodeForHeap* n1, NodeForHeap* n2)
{
	//Replaces the values ​​in the index array
	int tempIndex = IndexArry[n1->targetVertex];
	IndexArry[n1->targetVertex] = IndexArry[n2->targetVertex];
	IndexArry[n2->targetVertex] = tempIndex;

	//Replaces the values ​​of n1, n2
	NodeForHeap temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int Heap::Min()
{
	return data[0].targetVertex;
}
void Heap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (*(data[left].weight) < *(data[node].weight) && *(data[left].weight) != INITARRAY)|| 
	((left < heapSize)&& *(data[node].weight) == INITARRAY && *(data[left].weight) != INITARRAY)) //INITARRAY is a sign to infinity number
		min = left;
	else
		min = node;
	if ((right < heapSize) && (*(data[right].weight) < *(data[node].weight) && *(data[left].weight) != INITARRAY)||
		((right < heapSize) && *(data[node].weight) == INITARRAY && *(data[right].weight) != INITARRAY)) //INITARRAY is a sign to infinity number
		min = right;
	if (min != node)
	{
		Swap(data + node, data + min);
		FixHeap(min);
	}
}

void Heap::UpdateKey(int index)
{
	if ((*(data[Parent(IndexArry[index])].weight) > *(data[IndexArry[index]].weight))|| ((IndexArry[index] > 0) && *(data[Parent(IndexArry[index])].weight) == INITARRAY))
	{
		while ((IndexArry[index] > 0) && (*(data[Parent(IndexArry[index])].weight) > *(data[IndexArry[index]].weight)) || ((IndexArry[index] > 0) && *(data[Parent(IndexArry[index])].weight) == INITARRAY))
		{
			Swap(data + (IndexArry[index]), data + (Parent(IndexArry[index])));
		}
	}
	else
		FixHeap(IndexArry[index]);
}

int Heap::DeleteMin()
{
	if (heapSize < 1)
	{
		throw "The heap is empty!!";
	}
	NodeForHeap min = data[0];
	heapSize--;
	//data[0] = data[heapSize];
	Swap(data, data + heapSize);
	FixHeap(0);
	return min.targetVertex;
}

bool Heap::IsEmpty()
{
	return (this->heapSize == 0);
}

void Heap::DecreaseKey(int place, float newKey)
{
	*(this->data[this->IndexArry[place]].weight) = newKey;
	Heap::UpdateKey(place);
}

