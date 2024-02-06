#include <stdio.h>
#include "dlinkedlist.h"


// IMPLEMENTAÇÃO TEÓRICA DE UMA LISTA DUPLAMENTE ENCADEADA COM
// NÓ CABEÇALHO.

int main(int argc, char *argv[]) {
    Dlist *l = initializeList();
    appendFirst(l, 2);
    appendFirst(l, 4);
    LRdisplayList(l);
    RLdisplayList(l);




    if(!l || emptyList(l))
        puts("It's works");
    deallocList(&l);
}