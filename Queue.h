#pragma once
#include"Node.h"
#include <iostream>
using namespace std;

template<class Type>
class Queue
{
private:
	Node<Type>* front;
	int count;
	Node<Type>* rear;
public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
		count = 0;
	}
	bool EnQueue(Type item,float priority = 0)
	{
		Node<Type>* temp;
		Node<Type>* cur=front;
		temp = new Node<Type>;
		temp->set_item(item);
		temp->set_priority(priority);
		if (QueueEmpty())
		{
			front = temp;
			rear = temp;

		}
		else if (front->get_priority()< priority)
		{
			temp->set_next(front);
			front = temp;
		}
		else
		{
			while (cur->get_next() != NULL && cur->get_next()->get_priority()>= priority)
				cur = cur->get_next();
			if (!cur->get_next())
				rear = temp;
			temp->set_next(cur->get_next());
			cur->set_next (temp);
			
		}

		count++;
		return true;

	}
	bool DeQueue()
	{
		if (count == 0)
			return false;
		Node<Type>* delptr;
		delptr = front;
		if (count == 1)
		{
			rear = NULL;
			front = NULL;
		}
		else
		{
			front = front->get_next();
		}
		delptr->set_next(nullptr);
		delete delptr;
		count--;
		return true;
	}
	bool QueueEmpty()
	{
		return !count;
	}
	void DistroyQueue()
	{
		int c = count;
		for (int i = 0; i < c; i++)
			DeQueue();
	}
	Node<Type>* GetFront()
	{
		return front;
	}
	Node<Type>* GetRear()
	{
		return rear;
	}
	int GetCount()
	{
		return count;
	}
	Type Peek()
	{
		if (!QueueEmpty())
			return front->get_item();
		else
			return NULL;
	}
	
	~Queue()
	{
		DistroyQueue();
	}
	void print()
	{
		Node<Type>* temp = front;
		while (temp)
		{
			cout << temp->get_item() << "  ";
			temp = temp->get_next();
		}
		cout << endl;
	}
};

//TO BE MOVED TO A NEW DATA STRUCTURE
/*bool remove_cargo(Queue<Cargo*> q, int id, Cargo*& ptr)
{
	Node<Cargo*>* NodePtr = q.GetFront();
	while (NodePtr)
	{
		if (*(NodePtr->get_item()) == id)
		{
			if (NodePtr->get_next())
			{
				NodePtr->set_item(NodePtr->get_next()->get_item());
				NodePtr->set_next(NodePtr->get_next()->get_next());
			}
			else
			{
				NodePtr
			}
			return true;
		}
		NodePtr = NodePtr->get_next();
	}
	return false;
}*/


