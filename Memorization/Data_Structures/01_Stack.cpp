#include <iostream>
#define MAX_VALUE 10

using namespace std;

template<class T> class Stack
{
public:
	int top;
	int size;
	T *values;

	Stack()
	{
		size = MAX_VALUE;
		values = new T[size];
		top = -1;
	}

	~Stack()
	{
		delete[] values;
	}

	void push(T value)
	{
		if (!isFull())
			values[++top] = value;
		else
			cout << "Stack is Full!\n";
	}

	void pop()
	{
		if (!is_empty())
			top--;
		else
			cout << "Stack is Empty!\n";
	}

	T Top()
	{
		if (!is_empty())
			return values[top];
		else
			return NULL;
	}

	bool is_empty()
	{
		if (top < 0)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if (top + 1 == size)
			return true;
		else
			return false;
	}
};

template<typename T>
ostream& operator<<(ostream &out, Stack<T> &st)
{
	T *temp = st.values;
	out << "-----------\n";
	for (int i = st.top; i >= 0; i--)
		out << "	" << temp[i] << endl;
	out << "-----------\n";
	return out;
}

int main()
{
	Stack<int> st;

	cout << "Stack push" << endl;
	st.push(1);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(3);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(5);
	cout << st << endl;
	cout << "Stack Top : " << st.Top() << endl << endl;

	cout << "Stack pop" << endl;
	st.pop();
	cout << st << endl;
	st.pop();
	cout << "Stack pop" << endl;
	cout << st << endl;
	st.pop();
	cout << "Stack pop" << endl;
	cout << st << endl;
}