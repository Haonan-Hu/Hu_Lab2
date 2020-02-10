/*
Author: Haonan Hu
File: Hash_Table.h
Date:2/10/2020
Brief:File is header file
*/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Linked_list.h"
#include <stdexcept>
#include <iostream>

class HashTable
{
public:
  HashTable();
  ~HashTable();
  void addPlayer();
  void removePlayer();
  void printPlayersList();
private:
  hash(int goalCount, int size);
  
}
