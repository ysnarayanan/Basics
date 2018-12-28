#pragma once
#include "DLList.h"
class SortedDLList :
	public DLList
{
public:
	SortedDLList();
	~SortedDLList();
	virtual void addNode(int data);
};

