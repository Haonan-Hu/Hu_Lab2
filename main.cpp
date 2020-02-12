/*
Author: Haonan Hu
File: main.cpp
Date:2/10/2020
Brief:File is main file
*/

#include "Executive.h"
#include <stdexcept>
#include <string>
#include <iostream>

int main(int argc, char*argv[ ])
{
  if(argc < 2)
  {
    std::cout << "Wrong number of parameters\n";
  }
  else
  {//dsdasd
    executive exec(argv[1]);
    exec.run();
  }
  return 0;
}
