#include <stdio.h>
#include "dlinkedlist.h"


// IMPLEMENTAÇÃO TEÓRICA DE UMA LISTA DUPLAMENTE ENCADEADA COM
// NÓ CABEÇALHO.

int main(int argc, char *argv[]) {
    Dlist *list = initializeList();



    deallocList(&list);
    if(!list || emptyList(list))
        puts("It's works");
}