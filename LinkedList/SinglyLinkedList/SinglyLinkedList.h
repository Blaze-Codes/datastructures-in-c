#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h> // is also included in .c file


// Define node
typedef struct node {
  int value; // TODO: implement polymorphism later (unions?)
  struct node* next;
} node;

// Define some functions that a singly linked list should be able to do
void insert(int value);
bool contains(int value); // returns true if the value is already there
void delete(int value);

#endif