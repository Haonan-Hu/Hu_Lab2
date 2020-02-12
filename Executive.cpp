/*
Author: Haonan Hu
File: Executive.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Executive.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <limits>

executive::executive(std::string fileName)
{
  std::ifstream infile;
  infile.open(fileName);
  std::string data;
  std::string name;
  std::string temp;
  int score;

  if(infile.is_open())  //  file read successful
  {
    while(std::getline(infile, data)) // make sure file input is valid
    {
      int index = data.find(':');
      for(int i = 0; i < index; i++)
      {
        name = name + data.at(i);
      }
      for(int i = index + 1; i < data.length(); i++)
      {
        temp = temp + data.at(i);
      }
      std::cout << temp << '\n';
      score = stoi(temp);
      m_hash.addPlayer(score, name);
      name = "";
      temp = "";
    }
    infile.close();
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){}

void executive::run()
{
  int choice;
  for(;;)
  {
    std::cout << "make a selection: \n";
    std::cout << "1) AddPlayer\n";
    std::cout << "2) RemovePlayer\n";
    std::cout << "3) PrintPlayerList\n";
    std::cout << "4) PlayerWithGoalCountEqualTo(g)\n";
    std::cout << "5) PlayerWithNumGoalsGreaterThan(h)\n";
    std::cout << "6) PlayerWithNumGoalsLessThan(h)\n";
    std::cout << "7) Exit\n";
    std::cin >> choice;
    std::cout << '\n';
    while(1)
    {
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\n\n";
        std::cout << "..................................\n\n";
        std::cout << "Choose one operation from the options below: \n\n";
        std::cout << "1) AddPlayer\n";
        std::cout << "2) RemovePlayer\n";
        std::cout << "3) PrintPlayerList\n";
        std::cout << "4) PlayerWithGoalCountEqualTo(g)\n";
        std::cout << "5) PlayerWithNumGoalsGreaterThan(h)\n";
        std::cout << "6) PlayerWithNumGoalsLessThan(h)\n";
        std::cout << "7) Exit\n";
        std::cin >> choice;
        std::cout << '\n';
      }
      if(!std::cin.fail())
        break;
    }
    if(choice == 1)
    {
      std::string record;
      std::string name;
      std::string temp;
      int score;
      std::cout << "Enter a record to be inserted: \n\n";
      std::cin >> record;
      int index = record.find(':');
      for(int i = 0; i < index; i++)
      {
        name = name + record.at(i);
      }
      for(int i = index + 1; i < record.length(); i++)
      {
        temp = temp + record.at(i);
      }
      score = stoi(temp);

      std::cout << '\n';
      m_hash.addPlayer(score, name);
      std::cout << "Output:: Record is successfully inserted.\n";
      std::cout << "..................................\n\n";
    }
    else if(choice == 2)
    {
      std::string name;
      int score;
      std::cout << "Enter a record with required name to be removed: \n";
      std::cin >> name;
      std::cout << '\n';
      std::cout << "Enter a record with required score to be removed: \n";
      std::cin >> score;
      std::cout << '\n';
      try
      {
        if(m_hash.search(score, name))
        {
          m_hash.removePlayer(score, name);
          std::cout << "Player " << name << " has been removed from the hash table.\n";
        }
        else
          std::cout << "No record found\n";
      }
      catch(std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
      }
      std::cout << "..................................\n\n";
    }
    else if(choice == 3)
    {
      m_hash.printPlayersList();
      std::cout << "..................................\n\n";
    }
    else if(choice == 4)
    {
      int score;
      std::cout << "Enter the Goal count: \n";
      std::cin >> score;
      std::cout << '\n';
      m_hash.playerWithGoalCountEqualTo(score);
      std::cout << "..................................\n\n";
    }
    else if(choice == 5)
    {
      int score;
      std::cout << "Enter the Goal count: \n";
      std::cin >> score;
      std::cout << '\n';
      m_hash.playerWithNumGoalsGreaterThan(score);
      std::cout << "..................................\n\n";
    }
    else if(choice == 6)
    {
      int score;
      std::cout << "Enter the Goal count: \n";
      std::cin >> score;
      std::cout << '\n';
      m_hash.playerWithNumGoalsLessThan(score);
      std::cout << "..................................\n\n";
    }
    else if(choice == 7)
    {
      std::cout << "Program execution complete!\n";
      break;
    }
    else
    {
      std::cout << " Wrong input!\n\n";
      std::cout << "..................................\n\n";
    }
  }
}
