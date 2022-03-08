#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "NeighborhoodMatrixGraph.h"
#include "AdjacencyListGraph.h"
#include "Graph.h"
#include "Bellman-Ford.h"
#include "Heap.h"
#include "Dijkstra.h"
#include "PriorityQueueWithArray.h"
#include "chrono"
#include "iomanip"
#include <string>

void AlgoAdjacencyBellmanFord(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile);
void AlgoMatrixBellmanFord(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile);
void AlgoAdjacencyDijkstraheap(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile);
void AlgoAdjacencyDijkstrarray(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile);
void AlgoMatrixDijkstraarray(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile);
void AlgoMatrixDijkstraheap(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile);
string skipOnEmptyLine(ifstream& inFile);


int main(int argc, char* argv[])
{
	ifstream infile;
	infile.open(argv[1]);
	if(!infile)
	{
		cout << "The file is not open" << endl;
		exit(1);
	}
	Graph* ListGraph, *MatrixGraph;
	int numOfVertex, sourceVertexOfRoute, targetVertexRoute, sorceVertexOfAdj, targetVertexOfAdj;
	float weightOfAdj;
	// infile >> numOfVertex >> sourceVertexOfRoute >> targetVertexRoute;
	string line = skipOnEmptyLine(infile);
	if (line.size() == 0)
	{
		cout << "syntax error";
		exit(1);
	}
	numOfVertex = stoi(line);

	line = skipOnEmptyLine(infile);
	if (line.size() == 0)
	{
		cout << "syntax error";
		exit(1);
	}
	sourceVertexOfRoute = stoi(line);

	line = skipOnEmptyLine(infile);
	if (line.size() == 0)
	{
		cout <<"syntax error";
		exit(1);
	}
	targetVertexRoute = stoi(line);


	if(sourceVertexOfRoute<=0|| sourceVertexOfRoute> numOfVertex)
	{
		cout << "Worng source, Invailed input!!" << endl;

	}
	else if(targetVertexRoute <= 0 || targetVertexRoute > numOfVertex)
	{
		cout << "Worng destionation, Invailed input!!" << endl;

	}
	else
	{
		ListGraph = new AdjacencyListGraph(numOfVertex);
		MatrixGraph = new NeighborhoodMatrixGraph(numOfVertex);

		while (!infile.eof())
		{
			if (!infile)
			{
				cout << "Error reading" << endl;
				exit(1);
			}

			line = skipOnEmptyLine(infile);
			if (line.size() != 0)
			{
				sscanf(line.c_str(), "%d%d%f", &sorceVertexOfAdj, &targetVertexOfAdj, &weightOfAdj);

				//file >> sorceVertexOfAdj >> targetVertexOfAdj >> weightOfAdj;
				try
				{
					ListGraph->AddEdge(sorceVertexOfAdj, targetVertexOfAdj, weightOfAdj);
					MatrixGraph->AddEdge(sorceVertexOfAdj, targetVertexOfAdj, weightOfAdj);
				}
				catch (const char* msg)
				{
					cout << msg << endl;
					cout << "Invailed input!!" << endl;
					exit(1);

				}

			}
		}



		AlgoAdjacencyDijkstraheap(ListGraph, sourceVertexOfRoute, targetVertexRoute, argv[2]);

		AlgoAdjacencyDijkstrarray(ListGraph, sourceVertexOfRoute, targetVertexRoute, argv[2]);

		AlgoAdjacencyBellmanFord(ListGraph, sourceVertexOfRoute, targetVertexRoute, argv[2]);

		AlgoMatrixDijkstraheap(MatrixGraph, sourceVertexOfRoute, targetVertexRoute, argv[2]);

		AlgoMatrixDijkstraarray(MatrixGraph, sourceVertexOfRoute, targetVertexRoute, argv[2]);

		AlgoMatrixBellmanFord(MatrixGraph, sourceVertexOfRoute, targetVertexRoute, argv[2]);
	}
	infile.close();
	
	return 0;
}


void AlgoAdjacencyBellmanFord(Graph* g,int sourceVertex,int targetVertex, const char* outNameFile)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Bellman_Ford AdjacencyBellmanFord(g, sourceVertex);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outNameFile,ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function < Adjacency Bellman Ford > is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	if (AdjacencyBellmanFord.GetDArray()[targetVertex - 1] == -1)
	{
		cout << "There is no route between " << sourceVertex << " to " << targetVertex << endl;
	}
	else
	{
		cout << "Adjacency Bellman Ford " << AdjacencyBellmanFord.GetDArray()[targetVertex - 1] << endl;
	}
}

void AlgoMatrixBellmanFord(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Bellman_Ford MatrixBellmanFord(g, sourceVertex);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outNameFile, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function < Matrix Bellman Ford > is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	if (MatrixBellmanFord.GetDArray()[targetVertex - 1] == -1)
	{
		cout << "There is no route between " << sourceVertex << " to " << targetVertex << endl;
	}
	else
	{
		cout << "Matrix Bellman Ford " << MatrixBellmanFord.GetDArray()[targetVertex - 1] << endl;
	}
}

void AlgoAdjacencyDijkstraheap(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	PriorityQueue* q = new Heap();
	Dijkstra AdjacencyDijkstraheap(g, sourceVertex, q);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outNameFile,ios::trunc); // The name of the file which is in argv[2]

	myfile << "Time taken by function < Adjacency Dijkstra heap > is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	if (AdjacencyDijkstraheap.GetDArray()[targetVertex - 1] == -1)
	{
		cout << "There is no route between " << sourceVertex << " to " << targetVertex << endl;
	}
	else
	{
		cout << "Adjacency Dijkstra heap " << AdjacencyDijkstraheap.GetDArray()[targetVertex - 1] << endl;
	}
}

void AlgoAdjacencyDijkstrarray(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	PriorityQueue* q = new PriorityQueueWithArray();
	Dijkstra AdjacencyDijkstrarray(g, sourceVertex, q);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outNameFile, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function < Adjacency Dijkstra array > is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	if (AdjacencyDijkstrarray.GetDArray()[targetVertex - 1] == -1)
	{
		cout << "There is no route between " << sourceVertex << " to " << targetVertex << endl;
	}
	else
	{
		cout << "Adjacency Dijkstra array " << AdjacencyDijkstrarray.GetDArray()[targetVertex - 1] << endl;
	}
}

void AlgoMatrixDijkstraarray(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	PriorityQueue* q = new PriorityQueueWithArray();
	Dijkstra MatrixDijkstraarray(g, sourceVertex, q);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outNameFile, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function < Matrix Dijkstra array > is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	if (MatrixDijkstraarray.GetDArray()[targetVertex - 1] == -1)
	{
		cout << "There is no route between " << sourceVertex << " to " << targetVertex << endl;
	}
	else
	{
		cout << "Matrix Dijkstra array " << MatrixDijkstraarray.GetDArray()[targetVertex - 1] << endl;
	}


}

void AlgoMatrixDijkstraheap(Graph* g, int sourceVertex, int targetVertex, const char* outNameFile)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	PriorityQueue* q = new Heap();
	Dijkstra MatrixDijkstraheap(g, sourceVertex, q);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(outNameFile, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function < Matrix Dijkstra heap > is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	if (MatrixDijkstraheap.GetDArray()[targetVertex - 1] == -1)
	{
		cout << "There is no route between " << sourceVertex << " to " << targetVertex << endl;
	}
	else
	{
		cout << "Matrix Dijkstra heap " << MatrixDijkstraheap.GetDArray()[targetVertex - 1] << endl;
	}
}






string skipOnEmptyLine(ifstream& inFile)
{
	string line;
	getline(inFile, line);

	
	while (line.size() == 0 && !inFile.eof())
	{
		getline(inFile, line);
	}

	return line;
}