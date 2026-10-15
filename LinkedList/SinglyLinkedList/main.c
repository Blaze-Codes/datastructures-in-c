#include <stdio.h>
#include "SinglyLinkedList.h"

int main(void) {
    insert(10);
    insert(20);
    insert(30);

    printf("Contains 20? %s\n", contains(20) ? "Yes" : "No");
    printf("Contains 99? %s\n", contains(99) ? "Yes" : "No");

    delete(20);

    printf("Contains 20 after deletion? %s\n",
           contains(20) ? "Yes" : "No");

    return 0;
}
