#include "Bellman-Ford.h"


Bellman_Ford::Bellman_Ford(Graph* g, int vertex)
{
	this->numOfVertex = g->GetNumOfVetex();
	this->g = g;
	List ListAdj;
	
	Init(vertex);

	for(int i=0;i< numOfVertex;i++)
	{
		for(int j=1;j<=numOfVertex;j++)
		{
			ListAdj=g->GetAdjList(j);
			Node* curr = ListAdj.getHead();
			while(curr!=nullptr)
			{
				Relax(curr->sourceVertex,curr->targetVertex);
				curr = curr->next;
			}
			ListAdj.clear();
		}
	}	
}

void Bellman_Ford::Init(int vertex)
{
	d = new float[this->numOfVertex];
	p = new int[this->numOfVertex];

	for (int i = 0; i < this->numOfVertex; i++)
	{
		p[i] = INITARRAY;//init the parentes arrry
		if (i != vertex-1)
		{
			d[i] = INITARRAY;
		}
	}
	d[vertex - 1] = 0;
}

void Bellman_Ford::Relax(int vertex1, int vertex2)
{
	if ((d[vertex2] > d[vertex1] + g->GetWeightOfAdj(vertex1+1, vertex2+1)||d[vertex2]==INITARRAY)&&d[vertex1]!=INITARRAY)//If the route to vertx1 through vetex2 is better than the route we have so far to vertex1 we will adopt it We will update the weight to vertex1 and his parent
	{
		d[vertex2] = d[vertex1] + g->GetWeightOfAdj(vertex1+1, vertex2+1);
		p[vertex2] = vertex1;
	}
}


float* Bellman_Ford::GetDArray()
{
	return this->d;
}