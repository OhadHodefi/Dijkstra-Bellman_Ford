#include "PriorityQueueWithArray.h"


PriorityQueueWithArray::PriorityQueueWithArray()
{
	this->arr = nullptr;
}

PriorityQueueWithArray::PriorityQueueWithArray(int sizeOfArr, float* arr)
{
	Build(arr, sizeOfArr);
}

PriorityQueueWithArray::~PriorityQueueWithArray()
{
	if(this->arr!=nullptr)
		delete[] arr;
}

void PriorityQueueWithArray::Build(float* arrOfd, int size)
{
	this->numOfVertex = size;
	this->arr = new NodeForArray[size];

	// Updates any value in the deleteVertex array in the array to be false and gives it the appropriate weight according to array d
	for(int i=0;i<numOfVertex;i++)
	{
		arr[i].deleteVertex = false;
		arr[i].weight = arrOfd + i;
	}
}

int PriorityQueueWithArray::DeleteMin()
{
	int weightMin = INITARRAY, vertexMin = 0;
	//Finds the minimum value
	for(int i=0;i<numOfVertex;i++)
	{
		if(((*(this->arr[i].weight)< weightMin && *(this->arr[i].weight)!=INITARRAY)||
			(weightMin ==INITARRAY && *(this->arr[i].weight) != INITARRAY))&& (!this->arr[i].deleteVertex)) //INITARRAY is a sign to infinity number
		{
			weightMin = *(this->arr[i].weight);
			vertexMin = i;
		}
	}
	this->arr[vertexMin].deleteVertex = true;
	return vertexMin;
}

bool PriorityQueueWithArray::IsEmpty()
{
	bool res = true;
	for (int i = 0; i < numOfVertex; i++)
	{
		if (!arr[i].deleteVertex&&*(arr[i].weight)!=INITARRAY)
		{
			res = false;
		}
	}
	return res;
}

void PriorityQueueWithArray::DecreaseKey(int place, float newKey)
{
	*(this->arr[place].weight) = newKey;
}