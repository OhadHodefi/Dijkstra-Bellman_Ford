#pragma once
#include "Graph.h"
#include "PriorityQueue.h"

#define INITARRAY -1
class Dijkstra
{
	private:
		float* d;
		int* p;
		int numOfVertex;
		Graph* g;
	
	public:
		Dijkstra(Graph* g, int vertex, PriorityQueue* q);//Constructor
		void Init(int vertex);//This method initializes d and p arrays
		bool Relax(int vertex1, int vertex2);//This method does the relaxation action

		float* GetDArray();//This method returns the array d - at the end of the Belman-Ford run each d[i] has the lightest track weight from s to i
	
};
