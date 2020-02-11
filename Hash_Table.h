/*
Author: Haonan Hu
File: Hash_Table.h
Date:2/10/2020
Brief:File is header file
*/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Linked_List.h"
#include <stdexcept>
#include <iostream>

class HashTable
{
public:
  /**
	* @pre none
	*	@post creates an empty hashtable
	*/
  HashTable();
  /**
	* @pre none
	* @post deletes the whole hashtable
	* @return none
	*/
  ~HashTable();
  /**
	* @pre input has to be valid
	* @post add player at the back of list
	* @return none
	*/
  void addPlayer(int score, std::string playerName);
  /**
	* @pre the record must be valid
	* @post remove a player from hashtable
	* @return none
	*/
  void removePlayer(int score, std::string playerName);
  /**
	* @pre none
	* @post print all records of the hashtable
	* @return none
	*/
  void printPlayersList();
  void playerWithGoalCountEqualTo(int score);
  void playerWithNumGoalsGreaterThan(int score);
  void playerWithNumGoalsLessThan(int score);
  bool search(int score, std::string playerName);
  

private:
  LinkedList* m_arr;
  int m_size;
  /**
	* @pre input must be valid
	* @post complete the hash value of the index
	* @return none
	*/
  int hash(int score);

};
#endif
