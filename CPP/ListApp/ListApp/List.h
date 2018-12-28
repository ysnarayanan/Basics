#pragma once
#include "Node.h"
#include <vector>

using namespace std;

class List
{
public:
	List();
	~List();
	virtual void addNode(int data);
	virtual void deleteNode(int data);
	virtual vector<int> traverse();
	virtual void sort();
	virtual void reverse();
protected:
	Node * head;
};

