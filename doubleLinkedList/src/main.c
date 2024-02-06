#include <stdio.h>
#include "dlinkedlist.h"


// IMPLEMENTAÇÃO TEÓRICA DE UMA LISTA DUPLAMENTE ENCADEADA COM
// NÓ CABEÇALHO.

int main(int argc, char *argv[]) {
    Dlist *l = initializeList();
    appendLast(l, 10);
    appendLast(l, 2);
    appendLast(l, 4);
    appendLast(l, 7);
    LRdisplayList(l);
    RLdisplayList(l);
    delNode(l, 7);
    LRdisplayList(l);
    RLdisplayList(l);

    if(!l || emptyList(l))
        puts("It's works");
    deallocList(&l);
}