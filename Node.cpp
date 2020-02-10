/*
Author: Haonan Hu
File: Node.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Node.h"

Node::Node(int entry)
{
	m_entry = entry;
	m_next = nullptr;
}

void Node::setEntry(int entry)
{
	m_entry = entry;
}

int Node::getEntry()const
{
	return m_entry;
}

void Node::setNext(Node* next)
{
	m_next = next;
}

Node* Node::getNext()const
{
	return m_next;
}
