#include "stdafx.h"
#include "List.h"
#include <iostream>


using namespace std;

List::List()
{
}


List::~List()
{
}

void List::addNode(int data)
{
	Node* node = new Node(data);
	if (head == NULL)
	{
		head = node;
	}
	else
	{
		Node* temp = head;
		while (temp->getNext() != NULL)
		{
			temp = temp->getNext();
		}
		temp->setNext(node);
	}
}

void List::deleteNode(int data)
{ 
	Node* curr = head;
	Node* prev = NULL;
	while (curr != NULL)
	{
		if (data == curr->getData())
		{
			if (prev == NULL)
			{
				head = curr->getNext();
			}
			else
			{
				prev->setNext(curr->getNext());
			}
			delete curr;
			break;
		}
		else
		{
			prev = curr;
			curr = curr->getNext();
		}
	}
}

vector<int> List::traverse()
{
	Node* ptr = head;
	vector<int> v;
	while (ptr != NULL)
	{
		v.push_back(ptr->getData());
		ptr = ptr->getNext();
	}
	return v;
}

void List::sort()
{
	Node* oldHead = head;
	head = NULL;

	while (oldHead != NULL)
	{
		Node* oldNext = oldHead->getNext();
		oldHead->setNext(NULL);
		Node* curr = head; //current node in sorted list.
		Node* prev = NULL; //previouss node in sorted list.
	    //Find insertion point in sorted list.
		while (curr != NULL && oldHead->getData() > curr->getData())
		{
			//Advance to next node.
			prev = curr;
			curr = curr->getNext();
		}
		if (prev == NULL)
		{
			//insert as new head.
			oldHead->setNext(head);
			head = oldHead;
		}
		else
		{
			prev->setNext(oldHead);
			oldHead->setNext(curr);
		}

		oldHead = oldNext;
	}
}

void List::reverse()
{
	Node* ptr = head;
	head = NULL;
	while (ptr != NULL)
	{
		Node* next = ptr->getNext();
		ptr->setNext(head);
		head = ptr;
		ptr = next;
	}
}
