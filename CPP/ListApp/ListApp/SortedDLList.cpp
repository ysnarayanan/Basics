#include "stdafx.h"
#include "SortedDLList.h"


SortedDLList::SortedDLList()
{
}


SortedDLList::~SortedDLList()
{
}

void SortedDLList::addNode(int data)
{
	DLNode* node = new DLNode(data);
	DLNode* curr = head;
	DLNode* prev = NULL;

	//Find insertion point in sorted list.
	while (curr != NULL && data > curr->getData())
	{
		//Advance to next node.
		prev = curr;
		curr = curr->getNext();
	}
	if (prev == NULL)
	{
		//insert as new head.
		node->setNext(head);
		if (head != NULL)
		{
			head->setPrev(node);
		}
		head = node;
	}
	else
	{
		prev->setNext(node);
		node->setPrev(prev);
		node->setNext(curr);
		if (curr != NULL)
		{
			curr->setPrev(node);
		}
	}

	//update tail.
	DLNode* ptr = head;
	while (ptr != NULL)
	{
		tail = ptr;
		ptr = ptr->getNext();
	}

}
