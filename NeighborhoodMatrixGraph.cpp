#include "NeighborhoodMatrixGraph.h"

//Ctor. Initializes the graph to be large n by using MakeEmptyGraph
NeighborhoodMatrixGraph::NeighborhoodMatrixGraph(int numOfVertices)
{
	MakeEmptyGraph(numOfVertices);
}

//DisCtor. Releases dynamically allocated memory - the neighborhood matrix - arrOfAdjacencyMatrix
NeighborhoodMatrixGraph::~NeighborhoodMatrixGraph()
{
	for (int i = 0; i < numberOfVertex; i++)
	{
		delete[] arrOfAdjacencyMatrix[i];
	}
	delete[] arrOfAdjacencyMatrix;
}

//The method is given size n and creates a two-dimensional array that forms a neighborhood graph.
//arrOfAdjacencyMatrix[i][j] = -1 <-> There is no arc between i and j
void NeighborhoodMatrixGraph::MakeEmptyGraph(int numberOfVertex)
{
	this->numberOfVertex = numberOfVertex;
	arrOfAdjacencyMatrix = new float* [numberOfVertex];
	for (int i = 0; i < numberOfVertex; i++)
	{
		arrOfAdjacencyMatrix[i] = new float[numberOfVertex];
	}
	for (int i = 0; i < numberOfVertex; i++)
	{
		for (int j = 0; j < numberOfVertex; j++)
		{
			arrOfAdjacencyMatrix[i][j] = INITARRAY;//There is no arc between i and j
		}
	}
}

//The method returns true if the arc (v, u) belongs to the graph, and otherwise false.
bool NeighborhoodMatrixGraph::IsAdjacent(int vertex1, int vertex2)
{

	if (outOfRange(vertex1) || outOfRange(vertex2))
	{
		throw "the one of vertex is not exists";
	}
	if (arrOfAdjacencyMatrix[vertex1-1][vertex2-1] != INITARRAY)
	{
		return true;
	}
	return false;
}

//The method returns the list of neighbors of the vertex 'vertex'
List NeighborhoodMatrixGraph::GetAdjList(int vertex)
{
	List listOfNeighbor;

	for (int i = 0; i < numberOfVertex; i++)
	{
		if (arrOfAdjacencyMatrix[vertex-1][i] != INITARRAY)
		{
			listOfNeighbor.push_back(vertex-1,i, arrOfAdjacencyMatrix[vertex-1][i]);
		}
	}

	return listOfNeighbor;
}

//The method adds a new arc to the graph only if we maintain our constraints
//a simple graph and a positive arc value
void NeighborhoodMatrixGraph::AddEdge(int vertex1, int vertex2, float weight)
{
	if (weight < 0) //The weight of the Adjacent is little then 0
	{
		throw "The weight of the Adjacent is not positive";
	}
	if (vertex1 == vertex2)//Not a simple graph - an attempt to add a self-arc
	{
		throw "The veretex are same";
	}
	if (outOfRange(vertex1) || outOfRange(vertex2))//Not a valid i nput for vertex
	{
		throw "the one of vertex is not exists";
	}
	if (IsAdjacent(vertex1, vertex2))//Not a simple graph - an attempt to add a parallel arc
	{
		throw "The adjacency is exists";
	}
	arrOfAdjacencyMatrix[vertex1-1][vertex2-1] = weight;
}

void NeighborhoodMatrixGraph::RemoveEdge(int vertex1, int vertex2)
{
	if (!IsAdjacent(vertex1, vertex2))
	{
		throw "The adjacency is not exists";
	}
	arrOfAdjacencyMatrix[vertex1-1][vertex2-1] = INITARRAY;
}

bool NeighborhoodMatrixGraph::outOfRange(int vertex)
{
	if (vertex <= 0 || vertex > numberOfVertex)
	{
		return true;
	}
	return false;
}

int NeighborhoodMatrixGraph::GetNumOfVetex()
{
	return this->numberOfVertex;
}

float NeighborhoodMatrixGraph::GetWeightOfAdj(int vertex1, int vertex2)
{
	if (IsAdjacent(vertex1, vertex2))
	{
		return this->arrOfAdjacencyMatrix[vertex1-1][vertex2-1];
	}
	else
	{
		throw "The Adjacency is not exists";
	}
}

