Linked_list.o: Linked_list.h Linked_list.cpp Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Linked_list.cpp

Node.o: Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o
