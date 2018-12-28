#include "stdafx.h"
#include "DLNode.h"

DLNode::DLNode(int data) : Node(data)
{
	prev = NULL;

}

DLNode::DLNode()
{
}


DLNode::~DLNode()
{
}

DLNode * DLNode::getNext()
{
	return next;
}

void DLNode::setNext(DLNode * next)
{
	this->next = next;
}

DLNode * DLNode::getPrev()
{
	return prev;
}

void DLNode::setPrev(DLNode * prev)
{
	this->prev = prev;
}
