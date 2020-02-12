Because of the Hackathon, I really dont have much time to make the program cover all bad input situation,
so please follow those instructions to run the program:
  1): My input file format is: PlayerName1:(no space)Goals
                               PlayerName2:Goals
                               PlayerName3:Goals
                                        .
                                        .
                                        .
                                        etc
      Any other file format will not work
  2): In the Executive.cpp file, when you trying to insert a player with his record, please use the format:
      Player:(no space)Goals   for example I'm inserting myself, cin input will be:
        Enter the Record to be inserted:
        >Haonan:1997
        >Output:Record is successfully inserted
  I think that is all you should be careful with.

Memory leak checked:
==11673== Memcheck, a memory error detector
==11673== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11673== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==11673== Command: ./hashTable
==11673==
Wrong number of parameters
==11673==
==11673== HEAP SUMMARY:
==11673==     in use at exit: 0 bytes in 0 blocks
==11673==   total heap usage: 2 allocs, 2 frees, 73,728 bytes allocated
==11673==
==11673== All heap blocks were freed -- no leaks are possible
==11673==
==11673== For lists of detected and suppressed errors, rerun with: -s
==11673== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
