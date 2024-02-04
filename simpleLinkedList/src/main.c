#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char *argv[]) {

    linkedList *l = initializeList();
    displayList(l);
    appendFirst(l, 5);
    displayList(l);
    appendFirst(l, 4);
    displayList(l);

    appendFirst(l, 3);
    appendFirst(l, 3);
    displayList(l);
    delNode(l, 3);

    appendFirst(l, 2);
    displayList(l);

    appendFirst(l, 1);
    displayList(l);

    appendEnd(l, 8);
    displayList(l);

    delNode(l, 8);
    displayList(l);
    appendEnd(l, 4);

    appendEnd(l, 2);
    displayList(l);
    delNode(l, 4);
    printf("Num of nodes = %d\n", quantNodes(l));
    delNode(l, 8);
    displayList(l);
    deallocateList(l);

}
