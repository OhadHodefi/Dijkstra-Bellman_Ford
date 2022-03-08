#pragma once


class PriorityQueue
{
	
public:
	virtual void Build(float* arr, int size) =0;
	virtual int DeleteMin()=0;
	virtual bool IsEmpty()=0;
	virtual void DecreaseKey(int place, float newKey)=0;
};
