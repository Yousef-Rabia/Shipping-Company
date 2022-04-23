#pragma once
#include"Node.h"
#include <iostream>
using namespace std;
#include "Cargo.h"
#include "Truck.h"
template<class Type>
class LinkedList
{
private:
	int count;
	Node<Type>* First;
	Node<Type>* End;
public:
	LinkedList()
	{
		First = NULL;
		End = NULL;
		count = 0;
	}
	void InsertBegin(Type anitem)
	{
		Node<Type>* temp;
		temp = new Node<Type>;
		temp->set_item(item);
		if (IsEmpty())
			End = temp;
		else
		temp->set_next(First);
		First = temp;
		count++;
	}
	bool InsertIndex(Type anitem, int index)
	{
		if (index <= count && index >= 0)
		{
			if (index == 0)
				InsertBegin(anitem);
			else if (index == count)
				InsertEnd(anitem);
			else
			{
				Node<Type>* temp;
				temp = new Node<Type>;
				Node<Type>* cur = First;
				for (int i = 0; i < index - 1; i++)
					cur = cur->get_next;
				temp->set_next(cur->get_next());
				cur->set_next(temp);
				count++;
			}
			return true ;
		}
		else
		return false;
	}
	void InsertEnd(Type anitem)
	{
		Node<Type>* temp;
		temp = new Node<Type>;
		temp->set_item(item);
		if (IsEmpty())
			First = temp;
		else
			End->set_next(temp);
		End = temp;
		count++;
	}

	bool IsEmpty()
	{
		return !count;
	}
	void Print();

};

template<class Type>
inline void LinkedList<Type>::Print()
{
}
template<>
inline void LinkedList<Cargo*>::Print()
{
	Node<Cargo*>* temp = First;
	while (temp)
	{
		cout << temp->get_item()->GetID() << "  ";
		temp = temp->get_next();
		if (temp)
			cout << ',';
	}
}
template<>
inline void LinkedList<Truck*>::Print()
{
	Node<Truck*>* temp = First;
	while (temp)
	{
		cout << temp->get_item()->GetID() << "  ";
		temp = temp->get_next();
		if (temp)
			cout << ',';
	}
}