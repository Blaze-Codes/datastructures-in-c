CC = gcc
CFLAGS = -Wall -Wextra -std=c11

singly_linked_list: main.o SinglyLinkedList.o
	$(CC) $(CFLAGS) main.o SinglyLinkedList.o -o singly_linked_list

main.o: main.c SinglyLinkedList.h
	$(CC) $(CFLAGS) -c main.c

SinglyLinkedList.o: SinglyLinkedList.c SinglyLinkedList.h
	$(CC) $(CFLAGS) -c SinglyLinkedList.c

clean:
	rm -f *.o singly_linked_list

.PHONY: all clean

all: singly_linked_list
	rm -f *.o