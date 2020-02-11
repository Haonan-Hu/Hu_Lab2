/*
Author: Haonan Hu
File: Linked_List.cpp
Date:2/10/2020
Brief:File is cpp file
*/

#include "Linked_List.h"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList()
{
	m_front = nullptr;
	m_length = 0;
}

LinkedList::~LinkedList() //destructor
{
	Node* deletePtr = m_front;
	while(m_front != nullptr)
	{
		m_front = m_front->getNext();
		deletePtr->setNext(nullptr);
		delete deletePtr;
		deletePtr = m_front;
	}
	m_length = 0;
}

Node* LinkedList::targetNode(int position)const
{
	int index = 1;
	Node* temp = m_front;
	if(position > m_length || position < 1)
	{
		throw(std::runtime_error("Invalid Position.\n"));
	}
	else
	{
		while(index != position)
		{
			temp = temp->getNext();
			index++;
		}
		return temp;
	}
}

bool LinkedList::IsEmpty()const	//check if the linkedlist is empty
{
	if(m_front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::Length()const //get the current length of the link
{
	return m_length;
}

void LinkedList::Insert(int score, std::string playerName) //insert a new node at given position
{
	//	Case1: if the list is empty, then just set entry for m_front
	if(IsEmpty() == true)
	{
		m_front = new Node(score, playerName);
	}
	//	Case2: add new node at the front of list
	else
	{
		Node* frontPtr = m_front;
		while(frontPtr->getNext() != nullptr)
		{
			frontPtr = frontPtr->getNext();
		}
		Node* temp = new Node(score, playerName);
		frontPtr->setNext(temp);
	}
	m_length++;
}

void LinkedList::Delete(int score, std::string playerName)
{
	//	give error message if the list is empty
	if(IsEmpty() == true)
	{
		throw(std::runtime_error("The list is empty.\n"));
	}
	else
	{
		//	Case: Only one node in the list and the node needs to be deleted
		if(m_front->getNext() == nullptr && m_front->getScore() == score && m_front->getName() == playerName)
		{
			m_front = nullptr;
		}
		//	Case2: multiple nodes in the list
		else
		{
			for(int i = m_length; i > 0;i--)	//	Searching target from the back
			{
				Node* temp = targetNode(i);
				if(temp->getScore() == score && temp->getName() == playerName) //	Found target from the back
				{
					Node* prevNode = targetNode(i - 1);
					prevNode->setNext(temp->getNext());
					temp->setNext(nullptr);
					delete temp;
				}
			}
		}
		m_length--;
	}
}

Node* LinkedList::getFront()const
{
	return m_front;
}

void LinkedList::Print()
{
	if(IsEmpty() == true)
	{
		std::cout << "The list is empty.\n\n";
	}
	else
	{
		Node* curNode = m_front;

		while (curNode != nullptr)
		{
			if(curNode->getNext() != nullptr)
			{
				std::cout << curNode->getName() << ':' << curNode->getScore() << " -> ";
			}
			else
			{
				std::cout << curNode->getName() << ':' << curNode->getScore() << "\n";
			}
			curNode = curNode->getNext();
		}
	  std::cout << "\n";
	}
}

bool LinkedList::searchByName(std::string playerName)
{
	for(int i = 1; i <= m_length; i++)
	{
		if(targetNode(i)->getName() == playerName)
		{
			return true;
		}
	}
	return false;
}

bool LinkedList::searchByNameAndScore(int score, std::string playerName)
{
	Node* temp = m_front;
	if(score < 0)
	{
		throw(std::runtime_error("Invalid score.\n\n"));
	}
	else
	{
		for(int i = 0; i < m_length; i++)
		{
			if(temp->getName() == playerName && temp->getScore() == score)
			{
				return true;
			}
			temp = temp->getNext();
		}
		return false;
	}
}
