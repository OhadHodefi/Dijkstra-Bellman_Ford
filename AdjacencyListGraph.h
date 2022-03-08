#pragma once
#include "List.h"
#include "Graph.h"


class AdjacencyListGraph: public Graph
{
private:
	List* arrOfAdjacencyList;
	int numberOfVertex;
public:
	AdjacencyListGraph(int numberOfVertex);//constructor
	virtual ~AdjacencyListGraph();//destructor

	virtual float GetWeightOfAdj(int vertex1, int vertex2)throw(const char*);//The method returns the arc weight
	virtual int GetNumOfVetex()override;//The method returns the number of vertices in the graph
	virtual void MakeEmptyGraph(int numberOfVertex) override;//The method creates an empty graph
	virtual List GetAdjList(int vertex) override;//return list of neighbors ot this vertex
	virtual bool IsAdjacent(int vertex1, int vertex2)throw(const char*)override;//checks if vertex1 ans vertex2 are neighbors
	virtual void AddEdge(int vertex1, int vertex2, float weight)throw(const char*)override;//add edge from vertex1 to vertex2
	virtual void RemoveEdge(int vertex1, int vertex2)throw(const char*)override;//delete edge from vertex1 to vertex2

};

