/*
Author: Haonan Hu
File: Node.h
Date:2/10/2020
Brief:File is header file
*/
#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
private:
	std::string m_playerName;
	int m_score;
	Node* m_next;

	public:
	/**
	* @pre none
	* @post construct an item with given value
	* @param entry,the value of item
	*/
	Node(int m_score, std::string m_playerName);
	/**
	* @pre none
	* @post set the value of existing item
	* @param entry, the value of item
	*/
	void setScore(int score);
	/**
	* @pre none
	* @post get the value of a existing item
	* @return the value of item
	*/
	int getScore()const;
	/**
	* @pre none
	* @post the the next item of
	* @return the next item
	*/
	void setName(std::string playerName);

	std::string getName()const;

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
