/*
Author: Haonan Hu
File: Node.h
Date:1/30/2020
Brief:File is header file
*/
#ifndef NODE_H
#define NODE_H

class Node
{
	private:
	int m_entry;
	Node* m_next;

	public:
	/**
	* @pre none
	* @post construct an item with given value
	* @param entry,the value of item
	*/
	Node(int entry);
	/**
	* @pre none
	* @post set the value of existing item
	* @param entry, the value of item
	*/
	void setEntry(int entry);
	/**
	* @pre none
	* @post get the value of a existing item
	* @return the value of item
	*/
	int getEntry()const;
	/**
	* @pre none
	* @post the the next item of
	* @return the next item
	*/
	Node* getNext()const;
	/**
	* @pre none
	* @post set the next item
	* @return none
	* @param next, the next item
	*/
	void setNext(Node* next);
};
#endif
