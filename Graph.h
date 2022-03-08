#pragma once
#include "List.h"


class Graph
{
public:
	Graph()
	{
	}
	virtual  ~Graph()
	{
	}

	virtual float GetWeightOfAdj(int vertex1, int vertex2)throw(const char*) = 0;//Returns the arc weight of (vertex1,vertex2)
	virtual int GetNumOfVetex() = 0;//Returns the number of vertices
	virtual void MakeEmptyGraph(int numberOfVertex)=0;//create empty graph
	virtual List GetAdjList(int vertex)=0;//return list of neighbors ot this vertex
	virtual bool IsAdjacent(int vertex1, int vertex2)throw(const char*)=0;//checks if vertex1 ans vertex2 are neighbors
	virtual void AddEdge(int vertex1, int vertex2, float weight)throw(const char*)=0;//add edge from vertex1 to vertex2
	virtual void RemoveEdge(int vertex1, int vertex2)throw(const char*) = 0;//delete edge from vertex1 to vertex2


	
};
