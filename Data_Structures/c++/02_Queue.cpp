#include <iostream>
#define MAX_VALUE 101

using namespace std;

template<class T> class Queue
{
public:
	int front;
	int rear;
	int size;
	T *values;

	Queue()
	{
		size = MAX_VALUE;
		values = new T[size];
		front = 0;
		rear = 0;
	}

	~Queue()
	{
		delete[] values;
	}

	void push(T value)
	{
		if (!isFull())
		{
			values[rear] = value;
			rear = (rear + 1) % size;
		}
		else
			cout << "Queue is Full!\n";
	}

	void pop()
	{
		if (!isEmpty())
			front = (front + 1) % size;
		else
			cout << "Queue is Empty!\n";
	}

	bool isEmpty()
	{
		if (rear == front)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if ((rear + 1) % size == front)
			return true;
		else
			return false;
	}
};

template<typename T>
ostream& operator <<(ostream &out, Queue<T> &q){
	T *temp = q.values;
	out << "front [";
	for (int i = q.front; i < q.rear; i++)
	{
		out << temp[i];
		if (i < q.rear - 1) out << " | ";
	}
	out << " ] rear" << endl;
	return out;
}

int main()
{
	Queue<int> q;
	q.push(3);
	cout << q;
	q.push(103);
	cout << q;
	q.push(57);
	cout << q;

	q.pop();
	cout << q;
	q.push(22);
	cout << q;
	q.pop();
	cout << q;
	q.pop();
	cout << q;
	q.pop();
	cout << q;
	q.pop();
	cout << q;
}