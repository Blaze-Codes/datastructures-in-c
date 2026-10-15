#include <stdio.h>
#include <stdlib.h>  // malloc, free, exit

#include "SinglyLinkedList.h"



node *root = NULL; // declaration and (somewhat) initialisation

void insert(int value){ // note that for now, the int can not be NULL. TODO: Handle that when implementing polymorphism!
    struct node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        printf("No more memory. Out of luck buddy :,(");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;

    if(root == NULL){ // check if root is a NULL pointer (do I have to dereference?)
        root = newNode; // point root to our new node
        return;
    }

    // Precondition: new Node already in memory and root is not NULL (i.e. we need to traverse)
    struct node *curr = root;
    while(curr->next != NULL){curr = curr->next;} // traverse until the end
    curr->next = newNode;
}


bool contains(int value){
    struct node *curr = root;
    while(curr != NULL) { // possible since we look at the value before swapping to the next node, handles empty list correctly
        if(curr->value == value) return true;
        curr = curr->next;
    }
    return false; // did not find the value
}

void delete(int value){
    if (root == NULL) return; // Empty list, nothing to remove lol
    if(root->value == value){ // case: remove root
        // Notice that this part of the code, where root is the only element, is irrelevant. As root->next = NULL.
        // As such, such an explicit declaration is not needed. Still gonna retain this cause why not.
        /* if(root->next == NULL){ // root is the only element
            root = NULL; return;
        } */

        struct node *temp = root; // root is not the only element
        root = root->next;
        
        free(temp);
        return;
    }

    struct node *prev = NULL;
    struct node *curr = root; 
    while(curr != NULL){
        if(curr->value == value){ // target acquired. Initiation deletion protocol!
            struct node *temp = curr;
            prev->next = temp->next; // change pointer destination
            free(temp);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    // well, we traversed and it was not there lol
    // when you try your best and you don't succeed :,)
    printf("Linked list did not contain node with %d. Try again next time buddy.", value);
}
