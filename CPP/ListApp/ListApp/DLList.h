#pragma once
#include "List.h"
#include "DLNode.h"
class DLList :
	public List
{
public:
	DLList();
	~DLList();
	virtual void addNode(int data);
	virtual void deleteNode(int data);
	virtual vector<int> traverse();
	virtual void sort();
	virtual void reverse();
protected:
	DLNode * head;
	DLNode * tail;
};

