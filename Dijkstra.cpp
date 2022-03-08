#include  "Dijkstra.h"


Dijkstra::Dijkstra(Graph* g, int vertex, PriorityQueue* q)
{
	this->numOfVertex = g->GetNumOfVetex();
	this->g = g;
	int currVertex;
	List ListAdj;
	Init(vertex);

	q->Build(this->d, this->numOfVertex);

	while (!(q->IsEmpty()))
	{
		currVertex = q->DeleteMin();
		currVertex++;
		ListAdj = g->GetAdjList(currVertex);
		Node* curr = ListAdj.getHead();
		while (curr != nullptr)
		{
			if (Relax(curr->sourceVertex, curr->targetVertex))
			{
				q->DecreaseKey(curr->targetVertex, this->d[curr->targetVertex]);
			}
			curr = curr->next;
		}
		ListAdj.clear();
	}

}

void Dijkstra::Init(int vertex)
{
	d = new float[this->numOfVertex];
	p = new int[this->numOfVertex];

	for (int i = 0; i < this->numOfVertex; i++)
	{
		p[i] = INITARRAY;//init the parentes arrry
		if (i != vertex - 1)
		{
			d[i] = INITARRAY;//init the d arrry - d array represents the minimum track weight from s to i as of that running time. At the end of the run he represented the minimum track weight from s to i
		}
	}
	d[vertex - 1] = 0;
}

bool Dijkstra::Relax(int vertex1, int vertex2)
{
	if ((d[vertex2] > d[vertex1] + g->GetWeightOfAdj(vertex1 + 1, vertex2 + 1) || d[vertex2] == INITARRAY) && d[vertex1] != INITARRAY)//If the route to vertx1 through vetex2 is better than the route we have so far to vertex1 we will adopt it
																																		//We will update the weight to vertex1 and his parent
	{
		d[vertex2] = d[vertex1] + g->GetWeightOfAdj(vertex1 + 1, vertex2 + 1);
		p[vertex2] = vertex1;
		return true;
	}
	return false;
}


float* Dijkstra::GetDArray()
{
	return this->d;
}