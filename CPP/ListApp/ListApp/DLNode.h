#pragma once
#include "Node.h"
class DLNode :
	public Node
{
public:
	DLNode();
	DLNode(int data);
	~DLNode();
	DLNode* getNext();
	void setNext(DLNode* next);
	DLNode* getPrev();
	void setPrev(DLNode* prev);

protected:
	DLNode * next;
	DLNode* prev;
};

