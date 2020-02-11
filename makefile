hashTable: main.o executive.o Hash_Table.o Linked_List.o Node.o
	g++ -std=c++11 -g -Wall main.o executive.o Hash_Table.o Linked_List.o Node.o -o hashTable

main.o: main.cpp executive.h executive.cpp Hash_Table.h Hash_Table.cpp Linked_List.h Linked_List.cpp Node.h	Node.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp Hash_Table.h Hash_Table.cpp Linked_List.h Linked_List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

Hash_Table.o: Hash_Table.h Hash_Table.cpp Linked_List.h Linked_List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Hash_Table.cpp

Linked_List.o: Linked_list.h Linked_List.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Linked_List.cpp

Node.o: Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o hashTable
