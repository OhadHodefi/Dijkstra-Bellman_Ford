#include "List.h"



Node* List::createNewNode(int sourceVertex, int targetVertex, float _weight, Node* _next, Node* _prev)
{
	Node* newNode = new Node{ sourceVertex, targetVertex,_weight,_next,_prev };
	if (newNode == nullptr)
		throw "Meomry faild...";
	return newNode;
}
List::List() :head(nullptr), tail(nullptr), Length(0)
{}
List::~List()
{
	this->clear();
	
}
List::List(const List& lst)
{
	this->Length = 0;
	*this = lst;
}
Node* List::getHead()const
{
	return this->head;
}
Node* List::getTail()const
{
	return this->tail;
}
void List::push_back(int sourceVertex, int targetVertex, float _weight)
{
	Node* newNode = createNewNode(sourceVertex,targetVertex,_weight, nullptr, this->tail);
	if (empty())
	{
		this->tail = newNode;
		this->head = newNode;
	}
	else
	{
		this->tail->next = newNode;
		this->tail = newNode;
	}
	this->Length++;
}
void List::push_front(int sourceVertex, int targetVertex, float _weight)
{
	Node* newNode = createNewNode(sourceVertex, targetVertex, _weight, nullptr, this->tail);
	if (empty())
	{
		this->tail = newNode;
		this->head = newNode;
	}
		else
		{
			this->head->prev = newNode;
			this->head = newNode;
		}
		this->Length++;
}
void List::pop_back()
{
	Node* curr = this->tail;
	if (!empty())
	{
		if (this->Length == 1)
		{
			delete[] curr;
			this->Length = 0;
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			this->tail = curr->prev;
			delete[] curr;
			this->tail->next = nullptr;
			this->Length--;
		}
	}
}
void List::pop_front()
{
	Node* curr = this->head;
	if (!empty())
	{
		if (this->Length == 1)
		{
			delete[] curr;
			this->Length = 0;
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			this->head = curr->next;
			delete[] curr;
			this->head->prev = nullptr;
			this->Length--;
		}
	}
}
bool List::empty()const
{
	return this->Length == 0;
}
int List::front()const
{
	return this->head->weight;
}
int List::back()
{
	return this->tail->weight;
}
int List::size()const
{
	return this->Length;
}
void List::clear()
{
	Node* curr = head;
	while (curr != nullptr)
	{
		curr = curr->next;
		delete head;
		head = curr;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->Length = 0;
}
const List& List::operator=(const List& _lst)
{
	if (_lst.head == nullptr)
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->Length = 0;
	}
	else
	{
		Node* curr = _lst.head;
		while (curr != nullptr)
		{
			push_back(curr->sourceVertex, curr->targetVertex, curr->weight);
			curr = curr->next;
		}
		this->Length = _lst.Length;
	}
	return *this;
}
bool List::operator==(const List& _lst)
{
	Node* curr1 = this->head;
	Node* curr2 = _lst.head;
	bool flag = true;
	if (this->Length != _lst.Length)
		flag = false;
	while (curr1 != nullptr && flag)
	{
		if (curr1->weight != curr2->weight||curr1->sourceVertex!=curr2->sourceVertex||curr1->targetVertex!=curr2->targetVertex)
			flag = false;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return flag;
}
void List::PrintList()const
{
	Node* curr = this->head;
	for (int i = 1; i <= this->Length; i++)
	{
		cout << curr->sourceVertex << endl;
		cout << curr->targetVertex << endl;
		cout << curr->weight << endl;
		curr = curr->next;
	}
}
