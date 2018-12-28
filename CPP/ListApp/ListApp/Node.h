#pragma once
class Node
{
public:
	Node();
	Node(int data);
	~Node();
	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
protected:
	int data;
	Node* next;
};

