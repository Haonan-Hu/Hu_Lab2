/*
Author: Haonan Hu
File: Executive.h
Date:2/10/2020
Brief:File is header file
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Hash_Table.h"
#include <fstream>

class executive
{
public:
  executive(std::string fileName);
  ~executive();
  /**
  * @pre none
  * @post run the user controled panel
  */
  void run();
};
#endif
