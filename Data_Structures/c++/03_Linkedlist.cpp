#include<iostream>
using namespace std;
template <typename T> struct Node
{
public:
	T value;
	struct Node<T> *next = nullptr;
};
template <typename T> class SingleLinked_List
{
private:
	Node<T> *head;
	Node<T> *tail;
	int size = 0;
public:
	SingleLinked_List() : head(nullptr), tail(nullptr) {}
	~SingleLinked_List() {}
	void AddNode(T _value)
	{
		Node<T> *node = new Node<T>;
		size++;
		node->value = _value;
		node->next = nullptr;
		if (head == nullptr)
		{
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = tail->next;
		} 
	}
	void RemoveNode(T _value)
	{
		Node<T> *ptr = head;
		Node<T> *tmp = ptr;
		while (ptr != nullptr)
		{
			if (ptr->value == _value) { break; }
			else { 
				tmp = ptr; 
				ptr = ptr->next;
			}
		}
		if (ptr == nullptr)
		{
			cout << "찾을 수 없는 노드 입니다" << endl;
		}
		else
		{
			size--;
			cout << "삭제된 노드의 값: " << ptr->value << endl;
			tmp->next = ptr->next;
			delete ptr;
		}
	}
	
	void Show()
	{
		Node<T> *node = head;
		while (node != nullptr)
		{
			cout << node->value << "->";
			node = node->next;
		}
		cout << endl;
	}
	
	void DeleteList()
	{
		Node<T> *ptr = head;
		while (ptr != nullptr)
		{
			head = ptr->next;
			delete ptr;
			ptr = head;
		}
		delete head;
		size = 0;
		cout << "리스트가 삭제되었습니다" << endl;
	}
	
	void RemoveTail()
	{
		Node<T> *ptr = head;
		Node<T> *tmp = new Node<T>;
		while (ptr->next != nullptr)
		{
			tmp = ptr;
			ptr = ptr->next;
		}
		size--;
		tail = tmp;
		tail->next = nullptr;
		delete ptr;
	}
	
	void RemoveHead()
	{
		Node<T> *ptr = head;
		head = ptr->next;
		size--;
		delete ptr;
	}
	
	void AddHead(T _value)
	{
		Node<T> *ptr = new Node<T>();
		size++;
		ptr->next = head;
		ptr->value = _value;
		head = ptr;
	}
	
	void AddPosition(int _index, T _value)
	{
		if (size < _index || 0>_index)
		{
			cout << "해당하는 인덱스 값은 없습니다." << endl;
			return;
		}
		Node<T> *ptr = head;
		Node<T> *tmp = ptr;
		Node<T> *node = new Node<T>;
		node->value = _value;
		node->next = nullptr;
		for (int i = 0; i < _index-1; i++)
		{
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next = node;
		node->next = ptr;
		size++;
	}
	
	void SearchValue(T _value)
	{
		Node<T> *ptr = head;
		int index = 0;
		bool isFind = false;
		while (ptr != nullptr)
		{
			index++;
			if (ptr->value == _value)
			{
				cout << _value << " 값은 인덱스 " << index << " 번쨰에 있습니다" << endl;
				isFind = true;
				break;
			}
			ptr = ptr->next;
		}
		if (isFind == false)
		{
			cout << _value << " 값은 리스트 안에 없습니다. " << endl;
		}
	}
	
	int Size()
	{
		return size;
	}
};

int main()
{
	// 리스트 동적할당의 경우
	//SingleLinked_List<int> *List = new SingleLinked_List<int>();
	//List->add_node(10);
	//List->add_node(11);
	//List->show();
	//delete List;
	
	SingleLinked_List<int> List;
	List.AddNode(10);
	List.AddNode(11);
	List.AddHead(14);
	List.AddHead(18);
	List.AddHead(1);
	List.AddPosition(2, 7);
	List.Show();
	List.SearchValue(10);
	cout << "리스트의 크기 " << List.Size() << endl;
	
	List.AddHead(4); 
	List.AddNode(9);
	List.Show();
	cout << "리스트의 크기 " << List.Size() << endl;
	
	List.RemoveHead();
	List.RemoveTail();
	List.RemoveNode(14);
	List.SearchValue(14);
	
	List.Show();
	cout << "리스트의 크기 " << List.Size() << endl;
	
	List.DeleteList();
	List.AddNode(10);
	List.Show();
	cout << "리스트의 크기 " << List.Size() << endl;
	
	return 0;
}