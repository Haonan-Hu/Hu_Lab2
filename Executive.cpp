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

executive::executive(std::string fileName)
{
  std::ifstream infile;
  infile.open(fileName);
  std::string data;

  if(infile.is_open())  //  file read successful
  {
    int goal;
    while(infile >> data) // make sure file input is valid
    {
      infile >> goal;
      myList.Insert(goal, data);
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
    if(choice == 1) //  Checking empty list
    {
      // if(myList.IsEmpty() == true)
      // {
      //   std::cout << "The list is empty.\n\n";
      //   std::cout << "..................................\n\n";
      // }
      // else
      // {
      //   std::cout << "The list is not empty.\n\n";
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 2) // checking length of the list
    {
      // std::cout << "The length of the list is: " << myList.Length() << "\n\n";
      // std::cout << "..................................\n\n";
    }
    else if(choice == 3) // Insert to the list
    {
      // int entry;
      // std::cout << "Choose a number to be inserted: \n\n";
      // std::cin >> entry;
      // std::cin.ignore();
      // std::cout << '\n';
      // myList.Insert(entry);
      // if(myList.getFront()->getEntry() == entry)
      // {
      //   std::cout << entry << " is inserted.\n\n";
      //   std::cout << "..................................\n\n";
      // }
      // else
      // {
      //   std::cout << "Insert not successful.\n\n";
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 4) // Delete from the list
    {
      // int entry;
      // std::cout << "Choose a number to be deleted from the list: \n\n";
      // std::cin >> entry;
      // std::cin.ignore();
      // std::cout << '\n';
      // if(myList.Find(entry))
      // {
      //   try
      //   {
      //     myList.Delete(entry);
      //     std::cout << "The last occurence of " << entry << " has been deleted from the list.\n\n";
      //     std::cout << "..................................\n\n";
      //   }
      //   catch(std::runtime_error &rte)
      //   {
      //     std::cout << rte.what() << '\n';
      //     std::cout << "..................................\n\n";
      //   }
      // }
      // else
      // {
      //   std::cout << entry << " is not found in the list.\n\n";
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 5) //Delete duplicates from the list
    {
      // try
      // {
      //   myList.DeleteDuplicates();
      //   std::cout << "Duplicates deleted.\n\n";
      //   std::cout << "..................................\n\n";
      // }
      // catch(std::runtime_error &rte)
      // {
      //   std::cout << rte.what() << '\n';
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 6) // Find element in the list
    {
      // int entry;
      // std::cout << "Enter the number to find: \n\n";
      // std::cin >> entry;
      // std::cin.ignore();
      // std::cout << '\n';
      // try
      // {
      //   if(myList.Find(entry))
      //   {
      //     std::cout << entry << " is in the list.\n\n";
      //     std::cout << "..................................\n\n";
      //   }
      //   else
      //   {
      //     std::cout << entry << " is not found in the list.\n\n";
      //     std::cout << "..................................\n\n";
      //   }
      // }
      // catch(std::runtime_error &rte)
      // {
      //   std::cout << rte.what() << '\n';
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 7)// Find the next element
    {
      // int entry;
      // std::cout << "Enter the number to find its next element: \n\n";
      // std::cin >> entry;
      // std::cin.ignore();
      // std::cout << '\n';
      // if(!myList.IsEmpty())
      // {
      //   myList.FindNext(entry);
      //   std::cout << "..................................\n\n";
      // }
      // else
      //   std::cout << "The list is Empty.\n\n";
    }
    else if(choice == 8) // Print the list
    {
      try
      {
        myList.Print();
        std::cout << "..................................\n\n";
      }
      catch(std::runtime_error &rte)
      {
        std::cout << rte.what() << '\n';
        std::cout << "..................................\n\n";
      }
    }
    else if(choice == 9) //Print the Reverse list
    {
      // try
      // {
      //   myList.ReverseList();
      //   std::cout << "..................................\n\n";
      // }
      // catch(std::runtime_error &rte)
      // {
      //   std::cout << rte.what() << '\n';
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 10) //Print the element at the given position
    {
      // int position;
      // std::cout << "Choose a position to print element: \n\n";
      // std::cin >> position;
      // std::cin.ignore();
      // std::cout << '\n';
      // try
      // {
      //   myList.PrintAt(position);
      //   std::cout << "..................................\n\n";
      // }
      // catch(std::runtime_error &rte)
      // {
      //   std::cout << rte.what() << '\n';
      //   std::cout << "..................................\n\n";
      // }
    }
    else if(choice == 11)
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
