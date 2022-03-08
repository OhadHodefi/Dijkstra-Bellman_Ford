#pragma once
#include "Graph.h"

#define INITARRAY -1

class Bellman_Ford
{
private:
	float* d;//d[i] - Specifies the minimum track weight from s to i
	int* p;//p[i] - Specifies the parent of vertex i
	int numOfVertex;
	Graph* g;

public:
	Bellman_Ford(Graph* g, int vertex);//Constructor
	
	void Init(int vertex);//This method initializes d and p arrays
	void Relax(int vertex1, int vertex2);//This method does the relaxation action

	float* GetDArray();//This method returns the array d - at the end of the Belman-Ford run each d[i] has the lightest track weight from s to i
};
