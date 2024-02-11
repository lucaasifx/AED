#include "xavecoding_dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Desafio das listas autoreorganizáveis do canal xavecoding

// elementos são diferentes (sem repetição)
// menor custo = maior recorrência
    // custo calculado tomando quantos nós foram percorridos
    // até encontrar o elemenSto
// organizar a lista por recorrência
    // elemento deve ser encadeado em posição anterior ao elemento
    // que possui recorrência igual ou inferior
int main(int argc, char *argv[]) {

    Plist *l = initializeList();
    char command[11];
    int key;
    char prodname[100];
    float price;
    scanf("%s ", command);
    while(strcmp(command, "para")) {
        if(!strcmp(command, "add")) {
            scanf("%d %s %f", &key, prodname, &price);
            appendLast(l, key, prodname, price);
        }
        else if(!strcmp(command, "acessa")) {
            int key;
            scanf("%d", &key);
            acess(l, key);
        }
        scanf("%s", command);
    }
    puts("");
    displayList(l);
    deallocProductlist(&l);

    return 0;
}