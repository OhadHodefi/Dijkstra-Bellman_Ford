#include "AdjacencyListGraph.h"


AdjacencyListGraph::AdjacencyListGraph(int numberOfVertex)
{
	MakeEmptyGraph(numberOfVertex);
}
AdjacencyListGraph::~AdjacencyListGraph()
{
	delete[] this->arrOfAdjacencyList;
}

void AdjacencyListGraph::MakeEmptyGraph(int numberOfVertex)
{
	
	this->arrOfAdjacencyList = new List[numberOfVertex];
	
	this->numberOfVertex = numberOfVertex;
}

List AdjacencyListGraph::GetAdjList(int vertex)
{
	List listOfNeighbor;
	Node* curr = this->arrOfAdjacencyList[vertex-1].getHead();
	
	while (curr!=nullptr)
	{
		listOfNeighbor.push_back(curr->sourceVertex,curr->targetVertex,curr->weight);
		curr = curr->next;
	}

	return listOfNeighbor;
}

bool AdjacencyListGraph::IsAdjacent(int vertex1, int vertex2)
{

	if (vertex1 == vertex2) // Self - arc - that is, not a simple graph
	{
		throw "The veretex are same";
	}
	if (vertex1 > this->numberOfVertex || vertex2 > this->numberOfVertex || vertex1 <= 0 || vertex2 <= 0)//The vertex number is out of legal range
	{
		throw "the one of vertex is not exists";
	}
	Node* curr = this->arrOfAdjacencyList[vertex1-1].getHead();
	while (curr != nullptr)
	{
		if(curr->targetVertex==vertex2-1)
		{
			return true;
		}
		curr = curr->next;
	}
	return false;	
}
void AdjacencyListGraph::AddEdge(int vertex1, int vertex2, float weight)
{
	if(weight<0)//Checks if the weight is non-negative
	{
		throw "The weight of the Adjacent is not positive";
	}
	if(vertex1 == vertex2)//Self-arc - that is, not a simple graph
	{
		throw "The veretex are same";
	}
	if(vertex1>this->numberOfVertex|| vertex2 > this->numberOfVertex|| vertex1 <= 0 || vertex2 <= 0)//The vertex number is out of legal range
	{
		throw "the one of vertex is not exists";
	}
	
	if(IsAdjacent(vertex1,vertex2))//Checks if the arc already exists
	{
		throw "The adjacency is exists";
	}
	
	this->arrOfAdjacencyList[vertex1-1].push_back(vertex1-1,vertex2-1, weight);//Adds the arc

}
void AdjacencyListGraph::RemoveEdge(int vertex1, int vertex2)
{
	if (!IsAdjacent(vertex1, vertex2))
	{
		throw "The adjacency is not exists";
	}

	Node* curr = this->arrOfAdjacencyList[vertex1-1].getHead();
	bool TheEdgeIsExists = false;

	while (curr != nullptr && !TheEdgeIsExists)
	{
		if (curr->targetVertex == vertex2-1)
		{
			TheEdgeIsExists = true;
		}
		else
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
		}
	}
}

int AdjacencyListGraph::GetNumOfVetex()
{
	return this->numberOfVertex;
}

float AdjacencyListGraph::GetWeightOfAdj(int vertex1, int vertex2)
{
	if (IsAdjacent(vertex1, vertex2))
	{
		Node* curr = this->arrOfAdjacencyList[vertex1-1].getHead();
		while (curr != nullptr)
		{
			if (curr->targetVertex == vertex2-1)
			{ 
				return curr->weight;
			}
			curr = curr->next;
		}
	}
	else
	{
		throw "The Adjacency is not exists";
	}
}
