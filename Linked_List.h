/*
Author: Haonan Hu
File: Linked_List.h
Date:2/10/2020
Brief:File is header file
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <stdexcept> //for runtime_error


class LinkedList
{
	private:
	Node* m_front;
	int m_length;
	/**
	* @pre position must be valid
	* @post give the node pointer
	* @return node pointer
	*/
	Node* targetNode(int position)const;

	public:
	/**
	* @pre none
	*	@post creates an empty list
	*/
	LinkedList();
	/**
	* @pre none
	* @post deletes all nodes in the list that created before
	* @return none
	*/
	~LinkedList();
	/**
	* @pre none
	* @post verify the list is empty or not
	*	return true if the list is empty
	*/
	bool IsEmpty() const;
	/**
	* @pre none
	* @post get the length of the linkedlist
	* @return the linkedlist length
	*/
	int Length()const;
	/**
	* @post insert a new item at the front of list
	* @param value of element
	* @return none
	*/
	void Insert(int score, std::string playerName);
	/**
	* @pre the list is not empty
	* @post deletes the entry
	* @param the value of element
	* @return none
	*/
	void Delete(int score, std::string playerName);
	/**
	* @pre none
	* @post get the front node pointer
	* @return the front node pointer
	*/
	Node* getFront()const;
	/**
	* @pre none
	* @post print the list
	* @return
	*/
	void Print();
	bool searchByName(std::string playerName);
	bool searchByNameAndScore(int score, std::string playerName);
};
#endif
