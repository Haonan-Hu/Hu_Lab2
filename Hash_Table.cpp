/*
Author: Haonan Hu
File: Hash_Table.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Hash_Table.h"

HashTable::HashTable()
{
  m_size = 7;
  m_arr = new LinkedList[7];
}

HashTable::~HashTable()
{
  delete[] m_arr;
}

int HashTable::hash(int score)
{
  int hashIndex = score % 7;
  return hashIndex;
}

void HashTable::addPlayer(int score, std::string playerName)
{
  bool duplicate = false;
  int hashIndex = hash(score);
  for(int i = 0; i < m_size; i++)
  {
    if(m_arr[i].searchByName(playerName))
    {
      duplicate = true;
    }
  }
  if(!duplicate)
  {
    m_arr[hashIndex].Insert(score, playerName);
  }
  else
    std::cout << "The player has already exist\n";
}

void HashTable::removePlayer(int score, std::string playerName)
{
  int hashIndex = score % 7;
  if(m_arr[hashIndex].searchByNameAndScore(score, playerName))
  {
    m_arr[hashIndex].Delete(score, playerName);
  }
}

void HashTable::printPlayersList()
{
  for(int i = 0; i < m_size; i++)
  {
    std::cout << i << ": -> ";
    m_arr[i].Print();
    std::cout << "\n";
  }
}

void HashTable::playerWithGoalCountEqualTo(int score)
{
  int hashIndex = score % 7;
  bool exist = false;
  Node* temp = m_arr[hashIndex].getFront();
  for(int i = 0; i < m_arr[hashIndex].Length(); i++)
  {
    if(temp->getScore() == score)
    {
      std::cout << temp->getName() << ':' << temp->getScore() << '\n';
      exist = true;
    }
    temp = temp->getNext();
  }
  if(!exist)
  {
    std::cout << "No players found" << '\n';
  }
}

void HashTable::playerWithNumGoalsGreaterThan(int score)
{
  bool exist = false;
  for(int i = 0; i < 7; i++)
  {
    Node* temp = m_arr[i].getFront();
    for(int j = 0; j < m_arr[i].Length(); j++)
    {
      if(temp->getScore() >= score)
      {
        std::cout << temp->getName() << ':' << temp->getScore() << '\n';
        exist = true;
      }
      temp = temp->getNext();
    }
  }
  if(!exist)
  {
    std::cout << "No players found" << '\n';
  }
}

void HashTable::playerWithNumGoalsLessThan(int score)
{
  bool exist = false;
  for(int i = 0; i < 7; i++)
  {
    Node* temp = m_arr[i].getFront();
    for(int j = 0; j < m_arr[i].Length(); j++)
    {
      if(temp->getScore() <= score)
      {
        std::cout << temp->getName() << ':' << temp->getScore() << '\n';
        exist = true;
      }
      temp = temp->getNext();
    }
  }
  if(!exist)
  {
    std::cout << "No players found" << '\n';
  }
}

bool HashTable::search(int score, std::string playerName)
{
  bool exist = false;
  for(int i = 0; i < m_size; i++)
  {
    if(m_arr[i].searchByNameAndScore(score, playerName))
    {
      exist = true;
    }
  }
  return exist;
}
