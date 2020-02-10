/*
Author: Haonan Hu
File: Linked_list.cpp
Date:1/30/2020
Brief:File is cpp file
*/
#include "Node.h"
#include "Linked_list.h"
#include <stdexcept>
#include <iostream>
using namespace std;

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
		throw(runtime_error("Invalid Position.\n"));
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

void LinkedList::Insert(int entry) //insert a new node at given position
{
	//	Case1: if the list is empty, then just set entry for m_front
	if(IsEmpty() == true)
	{
		m_front = new Node(entry);
	}
	//	Case2: add new node at the front of list
	else
	{
		Node* temp = new Node(entry);
		temp->setNext(m_front);
		m_front = temp;
	}
	m_length++;
}

void LinkedList::Delete(int entry)
{
	//	give error message if the list is empty
	if(IsEmpty() == true)
	{
		throw(runtime_error("The list is empty.\n"));
	}
	else
	{
		//	Case1: Only one node in the list and the node needs to be deleted
		if(m_front->getNext() == nullptr && m_front->getEntry() == entry)
		{
			m_front = nullptr;
		}
		//	Case2: multiple nodes in the list
		else
		{
			if(m_front->getNext() != nullptr && m_front->getEntry() != entry)
			{
				bool flag = false;	// a flag for making sure only one duplicate will be deleted
				for(int i = m_length; i > 0;i--)	//	Searching target from the back
				{
					Node* temp = targetNode(i);
					if(temp->getEntry() == entry) //	Found target from the back
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

void LinkedList::DeleteDuplicates()
{
	if(IsEmpty() == true)
	{
		throw(runtime_error("The list is empty.\n\n"));
	}
	else
	{
		Node* temp1 = m_front;
		Node* temp2;
		Node* temp3;
		while(temp1 != nullptr && temp1->getNext() != nullptr)
		{
			temp2 = temp1;
			while(temp2->getNext() != nullptr)
			{
				temp3 = temp2->getNext();

				if(temp1->getEntry() == temp3->getEntry())
				{
					Node* dup = temp3;
					temp2->setNext(temp3->getNext());
					delete dup;
					m_length--;
				}
				else
					temp2 = temp2->getNext();
			}
			temp1 = temp1->getNext();
		}
	}
}

bool LinkedList::Find(int entry)
{
	if(!IsEmpty())
	{
		bool found = false;
		for(int i = m_length; i > 0; i--)
		{
			if(targetNode(i)->getEntry() == entry)
			{
				found = true;
			}
		}
		return found;
	}
	else
	{
		throw(runtime_error("The list is empty.\n\n"));
	}
}

void LinkedList::FindNext(int entry)
{
	bool check = false;
	for(int i = 1; i <= m_length; i++)
	{
		if(targetNode(i)->getEntry() == entry && targetNode(i)->getNext() == nullptr)
		{
			cout << "None.\n\n";
			check = true;
		}
		else if(targetNode(i)->getEntry() == entry)
		{
			cout << targetNode(i)->getNext()->getEntry() << " is next after " << entry << ".\n\n";
			check = true;
		}
		if(check)
		{
			break;
		}
	}
	if(check == false)
	{
		cout << "There is no element " << entry << " in list. Hence there is no next element.\n\n";
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
		throw(runtime_error("The list is empty.\n\n"));
	}
	else
	{
		Node* curNode = m_front;

		while (curNode != nullptr)
		{
			cout << curNode->getEntry() << "->";
			curNode = curNode->getNext();
		}
	  cout << "\n\n";
	}
}

void LinkedList::ReverseList()
{
	if(!IsEmpty())
	{
		for(int i = m_length; i > 0; i--)
		{
			cout << targetNode(i)->getEntry() << "->";
		}
		cout << "\n\n";
	}
	else
	{
		throw(runtime_error("The list is empty.\n\n"));
	}
}

void LinkedList::PrintAt(int position)
{
	if(position > m_length || position < 1)
	{
		throw(runtime_error("Invalid position.\n\n"));
	}
	else
	{
		cout << "The element at the " << position << "th position is: " << targetNode(position)->getEntry() << "\n\n";
	}
}
