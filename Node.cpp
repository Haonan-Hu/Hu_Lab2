/*
Author: Haonan Hu
File: Node.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Node.h"

Node::Node(int score, std::string playerName)
{
	m_score = score;
	m_playerName = playerName;
	m_next = nullptr;
}

void Node::setScore(int score)
{
	m_score = score;
}

int Node::getScore()const
{
	return m_score;
}

void Node::setName(std::string playerName)
{
	m_playerName = playerName;
}

std::string Node::getName()const
{
	return m_playerName;
}

void Node::setNext(Node* next)
{
	m_next = next;
}

Node* Node::getNext()const
{
	return m_next;
}
