#pragma once
#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	Node* head;
	size_t size;

	void copy(Stack<T>& other)
	{
		this->size = other.size;
		this->head = new Node(other.head->data);
		Node* original = other.head;
		Node* copyNode = this->head;

		while (original->next != nullptr)
		{
			copyNode->next = new Node(original->next->data);
			copyNode = copyNode->next;
			original = original->next;
		}
	}

	void erase()
	{
		Node* holder = nullptr;
		while (this->head != nullptr)
		{
			holder = this->head->next;
			delete this->head;
			this->head = holder;
		}
		this->size = 0;
	}

public:

	Stack()
	{
		this->size = 0;
		this->head = nullptr;
	}

	Stack(Stack<T>& other)
	{
		this->copy(other);
	}

	Stack& operator=(Stack<T>& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}

		return *this;
	}

	~Stack()
	{
		this->erase();
	}

	size_t sizeOfStack() const
	{
		return this->size;
	}

	bool empty() const
	{
		return this->head == nullptr;
	}

	T& top() const
	{
		if (!this->empty())
		{
			return this->head->data;
		}
	}

	void push(const T& data)
	{
		Node* newNode = new Node(data);

		if (this->head != nullptr)
		{
			newNode->next = this->head;
		}

		this->head = newNode;
		this->size++;
	}

	void pop()
	{
		if (this->size != 0)
		{
			Node* holder = this->head->next;
			if (holder != nullptr)
			{
				int data = holder->data;
				delete this->head;
				this->head = holder;
			}

			else
			{
				delete this->head;
				this -> head = nullptr;
			}

			this->size--;
		}
	}

	void printStack()
	{
		while (!this->empty())
		{
			cout << this->top();
			this->pop();
		}
		cout << endl;
	}
};