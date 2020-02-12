hashTable: main.o Executive.o Hash_Table.o Linked_List.o Node.o
	g++ -std=c++11 -g -Wall main.o Executive.o Hash_Table.o Linked_List.o Node.o -o hashTable

main.o: main.cpp Executive.h Executive.cpp Hash_Table.h Hash_Table.cpp Linked_List.h Linked_List.cpp Node.h	Node.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Eecutive.o: Executive.h Executive.cpp Hash_Table.h Hash_Table.cpp Linked_List.h Linked_List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Hash_Table.o: Hash_Table.h Hash_Table.cpp Linked_List.h Linked_List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Hash_Table.cpp

Linked_List.o: Linked_List.h Linked_List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Linked_List.cpp

Node.o: Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o hashTable
