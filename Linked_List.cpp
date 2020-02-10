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
		Node* temp = new Node(score, playerName);
		temp->setNext(m_front);
		m_front = temp;
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
		//	Case1: Only one node in the list and the node needs to be deleted
		if(m_front->getNext() == nullptr && m_front->getScore() == score)
		{
			m_front = nullptr;
		}
		//	Case2: multiple nodes in the list
		else
		{
			if(m_front->getNext() != nullptr && m_front->getScore() != score)
			{
				bool flag = false;	// a flag for making sure only one duplicate will be deleted
				for(int i = m_length; i > 0;i--)	//	Searching target from the back
				{
					Node* temp = targetNode(i);
					if(temp->getScore() == score) //	Found target from the back
					{
						Node* prevNode = targetNode(i - 1);
						prevNode->setNext(temp->getNext());
						temp->setNext(nullptr);
						delete temp;
						flag = true;
					}
					if(flag) // activate flag if one duplicate deleted
					{
						break;
					}
				}
			}
			else
			{
				Node* temp = m_front;
				m_front = m_front->getNext();
				delete temp;
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
		throw(std::runtime_error("The list is empty.\n\n"));
	}
	else
	{
		Node* curNode = m_front;

		while (curNode != nullptr)
		{
			std::cout << curNode->getName() << ':' << curNode->getScore() << "->";
			curNode = curNode->getNext();
		}
	  std::cout << "\n\n";
	}
}


void LinkedList::PrintAt(int position)
{
	if(position > m_length || position < 1)
	{
		throw(std::runtime_error("Invalid position.\n\n"));
	}
	else
	{
		std::cout << "The element at the " << position << "th position is: " << targetNode(position)->getScore() << "\n\n";
	}
}
