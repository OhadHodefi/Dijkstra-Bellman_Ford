#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	int sourceVertex;
	int targetVertex;
	float weight;
	Node* next;
	Node* prev;
};

class List
{
private:
	Node* head;
	Node* tail;
	int Length;
	Node* createNewNode(int sourceVertex,int targetVertex, float _weight, Node* _next, Node* _prev) throw(const char*);
public:
	List();//constructor
	~List();//destructor
	List(const List& lst);//copy constructor 
	Node* getHead()const;//return the head that include data, next and prev
	Node* getTail()const;//return the tail that include data, next and prev
	Node* getNext()const;//return the next node of this node
	Node* getPrev()const;//return the pre node of this node
	void push_back(int sourceVertex, int targetVertex, float _weight);
	void push_front(int sourceVertex, int targetVertex, float _weight);
	void pop_back();//delete head
	void pop_front();//delete tail       
	bool empty()const;//checks if the list is empty
	int front()const;// return the data of the head
	int back();// return the data of the head
	int size()const;// return the size of the head
	void clear();//delete the list
	const List& operator=(const List& _lst);
	bool operator==(const List& _lst);
	void PrintList()const;//print the list
};






