#include "stdafx.h"
#include <iostream>
#include "DLList.h"

using namespace std;

DLList::DLList()
{
}


DLList::~DLList()
{
}

void DLList::addNode(int data)
{
	DLNode* node = new DLNode(data);

	if (head == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		DLNode* last = tail;
		last->setNext(node);
		node->setPrev(last);
		tail = node;
	}
}

void DLList::deleteNode(int data)
{
	DLNode* curr = head;
	DLNode* prev = NULL;
	while (curr != NULL)
	{
		if (data == curr->getData())
		{
			DLNode* next = curr->getNext();
			if (prev == NULL)
			{
				//first node
				head = next;
			}
			else
			{
				prev->setNext(next);
			}
			if (next != NULL)
			{
				next->setPrev(prev);
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

vector<int> DLList::traverse()
{
	DLNode* ptr = head;
	vector<int> v;
	while (ptr != NULL)
	{
		v.push_back(ptr->getData());
		ptr = ptr->getNext();
	}
	return v;
}

void DLList::sort()
{
	DLNode* oldHead = head;
	head = NULL;
	tail = NULL;

	while (oldHead != NULL)
	{
		DLNode* oldNext = oldHead->getNext();
		oldHead->setNext(NULL);
		oldHead->setPrev(NULL);
		DLNode* curr = head; //current node in sorted list.
		DLNode* prev = NULL; //previouss node in sorted list.
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
			if (head != NULL)
			{
				head->setPrev(oldHead);
			}
			head = oldHead;
		}
		else
		{
			prev->setNext(oldHead);
			oldHead->setPrev(prev);
			oldHead->setNext(curr);
			if (curr != NULL)
			{
				curr->setPrev(oldHead);
			}
		}

		oldHead = oldNext;
	}

	//update tail.
	DLNode* ptr = head;
	while (ptr != NULL)
	{
		tail = ptr;
		ptr = ptr->getNext();
	}
}

void DLList::reverse()
{
	//Swap next & prev links at each node.
	DLNode* ptr = head;
	while (ptr != NULL)
	{
		DLNode* next = ptr->getNext();
		DLNode* prev = ptr->getPrev();
		ptr->setNext(prev);
		ptr->setPrev(next);
		ptr = next;
	}

	DLNode* temp = head;
	head = tail;
	tail = temp;
}
