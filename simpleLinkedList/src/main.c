#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char *argv[]) {

    linkedList *l = initializeList();
    displayList(l);

    appendFirst(l, 5);
    printf("%d\n", l->head->key);
    displayList(l);
    puts("");

    appendFirst(l, 4);
    displayList(l);
    puts("");

    appendFirst(l, 3);
    displayList(l);
    puts("");

    appendFirst(l, 3);
    displayList(l);
    puts("");

    appendFirst(l, 2);
    displayList(l);
    puts("");

    appendFirst(l, 1);
    displayList(l);
    puts("");

    appendEnd(l, 8);
    displayList(l);
    puts("");

    appendEnd(l, 4);
    displayList(l);
    puts("");

    appendEnd(l, 2);
    displayList(l);
    puts("");
    
    puts(" *********** Before *************");
    displayList(l);
    puts(" *********** After *************");
    delAllnodes(l, 4);
    displayList(l);
    deallocateList(&l);

}
