#include "stdafx.h"
#include "SortedList.h"


SortedList::SortedList()
{
}


SortedList::~SortedList()
{
}

void SortedList::addNode(int data)
{
	Node* node = new Node(data);
	Node* curr = head; 
	Node* prev = NULL; 

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
		head = node;
	}
	else
	{
		prev->setNext(node);
		node->setNext(curr);
	}

}
