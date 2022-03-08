#pragma once
#include "List.h"
#include "Graph.h"
#define INITARRAY -1

class NeighborhoodMatrixGraph: public Graph
{
private:
	float** arrOfAdjacencyMatrix;
	int numberOfVertex;
	bool outOfRange(int vertex);//Returns true if the vertex is larger or smaller than its legal value range, otherwise false
public:
	NeighborhoodMatrixGraph(int numOfVertices);
	virtual ~NeighborhoodMatrixGraph();

	virtual float GetWeightOfAdj(int vertex1, int vertex2)throw(const char*)override;//Returns the arc weight of (vertex1,vertex2)
	virtual int GetNumOfVetex()override;//Returns the number of vertices in the graph
	virtual void MakeEmptyGraph(int numberOfVertex)override;//create wmpty graph
	virtual List GetAdjList(int vertex) override;//return list of neighbors ot this vertex
	virtual bool IsAdjacent(int vertex1, int vertex2)throw(const char*) override;//checks if vertex1 ans vertex2 are neighbors
	virtual void AddEdge(int vertex1, int vertex2, float weight)throw(const char*) override;//add edge from vertex1 to vertex2
	virtual void RemoveEdge(int vertex1, int vertex2)throw(const char*) override;//delete edge from vertex1 to vertex2

};
