#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	next = NULL;
}

Node::Node(int data) : data(data)
{
	//this->data = data;
	next = NULL;
}

Node::~Node()
{
}

int Node::getData()
{
	return data;
}

void Node::setData(int data)
{
	this->data = data;
}

Node * Node::getNext()
{
	return next;
}

void Node::setNext(Node * next)
{
	this->next = next;
}
