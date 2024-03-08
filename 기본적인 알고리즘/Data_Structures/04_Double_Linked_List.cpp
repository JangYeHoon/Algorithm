#include <iostream>

using namespace std;

class Node {
	friend class List;
private:
	Node* next;
	Node* prev;
	int value;
	Node(Node* n, Node* p, int v)
	{
		next = n;
		prev = p;
		value = v;
	}
	Node(int v)
	{
		next = nullptr;
		prev = nullptr;
		value = v;
	}
};

class List {
private:
	Node* head;
	Node* tail;
	int size;

public:
	List(int);
	void insertHead(int);
	void insertTail(int);
	void insert(int, int);
	void deleteHead();
	void print();
	~List();
};

List::List(int value)
{
	tail = head = new Node(value);
	size = 1;
}

void List::insertHead(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr)
	{
		tail = head;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
	}
	head = newNode;
	size++;
}

void List::insertTail(int value)
{
	Node* newNode = new Node(value);
	if (tail == nullptr)
	{
		head = tail;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
	}
	tail = newNode;
	size++;
}

void List::insert(int idx, int value) 
{
	/* index : start 0 */
	if (idx < 0 || idx >= size)
	{
		cout << "인덱스 범위 초과" << endl;
		return;
	}
	else if (idx == 0)
	{
		insertHead(value);
	}
	else if (idx == size - 1)
	{
		insertTail(value);
	}
	else
	{
		Node* newNode = new Node(value);
		Node* cur = head;
		int i = 0;
		while (i < idx - 1)
		{
			cur = cur->next; i++;
		}
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		cur->prev = newNode->prev;
	}
	size++;
}

void List::deleteHead()
{
	if (head != nullptr)
	{
		Node* remove = head;
		head = head->next;
		head->prev = nullptr;
		delete remove;
		size--;
	}
}

void List::print()
{
	Node* cur = head; 
	while(cur != nullptr)
	{
		if (cur->next == nullptr)
		{
			cout << cur->value << endl;
		}
		else
		{
			cout << cur->value << " ↔ ";
		}
		cur = cur->next;
	}
}

List::~List()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		deleteHead();
	}
}

int main(void)
{
	List* list = new List(1);
	for (int i = 3; i <= 6; i++)
	{
		list->insertHead(i);
	}
	list->print();
	list->deleteHead();
	for (int i = 10; i <= 13; i++)
	{
		list->insertTail(i);
	}
	list->print();
	list->insert(6, 77);
	list->insert(1, 88);
	list->print();
}