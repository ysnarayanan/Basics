#pragma once
#include "List.h"
class SortedList :
	public List
{
public:
	SortedList();
	~SortedList();
	void addNode(int data);
};

