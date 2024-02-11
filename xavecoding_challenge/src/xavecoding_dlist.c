#include "xavecoding_dlist.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int key;
    char name[100];
    float price;
} Product;

typedef struct node {
    struct node *prev;
    struct node *next;
    Product *prod;
    int recurrence;
} Node;

typedef struct plist {
    Node *head;
    Node *tail;
    int tcost, quantProducts;
} Plist;


Plist *initializeList() {
    Plist *l = (Plist *) malloc(sizeof(Plist));
    if(!l) {
        puts("Allocatio error!");
        exit(1);
    }
    l->head = NULL;
    l->tail = NULL;
    l->tcost = l->quantProducts = 0;
    return l;
}

Product *createProduct(int key, char *name, float price) {
    Product *p = (Product *) malloc(sizeof(Product));
    if(!p) {
        puts("Allocatio error!");
        exit(1);
    }
    p->key = key;
    strcpy(p->name, name);
    p->price = price;
    return p;
}

Node *createNode(int key, char *name, float price) { 
    Node *n = (Node *) malloc(sizeof(Node));
    if(!n) {
        puts("Allocatio error!");
        exit(1);
    }
    n->next = NULL;
    n->prev = NULL;
    n->prod = createProduct(key, name, price);
    n->recurrence = 0;
    return n;
}

void displayProduct(const Product *p) {
    printf("%d, %s, %.2f\n", p->key, p->name, p->price);
}

bool emptyList(const Plist *headList) {
    return !headList->quantProducts;
}


void appendLast(Plist *headList, int key, char *name, float price) {
    Node *n = createNode(key, name, price);
    n->prev = headList->tail;
    if(emptyList(headList))
        headList->head = n;
    else
        headList->tail->next = n;
    headList->tail = n;
    headList->quantProducts++;
}

void acess(Plist *headList, int key) {
    if(emptyList(headList))
        return;
    else {
        Node *backup = headList->head;
        int cost = 1; // acessar a cabeça já é um acesso
        while (backup && backup->prod->key != key) {
            cost++;
            backup = backup->next;
        }
        // existe um nó com essa key
        if(backup) {
            backup->recurrence++;
            headList->tcost += cost;
            // se o nó for a cabeça, não há necessidade de corrigir o encadeamento
            if(backup != headList->head) {
                // CORREÇÃO DO ENCADEAMENTO
                    // encadeamento corrigido em tempo de execução
                    // nós críticos:
                        // backup->next :(garante que não perderemos os nós sucessores)
                        // aux->prev: (garante que não perderemos os nós antecessores)
                Node *aux = backup->prev;
                while(aux && backup->recurrence >= aux->recurrence) {
                    // salva a referência dos nós antecessores
                    backup->prev = aux->prev;
                    // salva a referência dos nós sucessores
                    aux->prev = backup;

                    // correção do encadeamento:
                    aux->next = backup->next;
                    backup->next = aux;
                    if(backup->prev)
                        backup->prev->next = backup;
                    else
                        headList->head = backup;
                    if(aux->next)
                        aux->next->prev = aux;
                    else
                        headList->tail = aux;
                    
                    // nó anterior agora é o backup 
                    aux = backup->prev;
                }
            }
            // exibe o produto
            displayProduct(backup->prod);
        }
        else
            printf("Produto %d inexistente\n", key);
    }
}


void displayList(Plist *headList) {
    printf("L = (");
    Node *backup = headList->head;
    while(backup->next) {
        printf("%d, ", backup->prod->key);
        backup = backup->next;
    }
    printf("%d)\n", backup->prod->key);
    printf("Custo total = %d\n",headList->tcost);
}


// ********************* DESALOCAÇÃO ***********************************
// cada nó utiliza é alocado duas vezes, uma para o produto, outra para o nó

// para desalocar a estrutura, é necessário realizar duas desalocações por nó

// ponteiro para ponteiro permite modificar não só o conteúdo apontado pela estrutura
// mas a própria estrutura

void deallocProduct(Product **p) {
    Product *prod = *p;
    free(prod);
    *p = NULL;
}

void deallocNode(Node **n) {
    Node *nodebackup = *n;
    deallocProduct(&nodebackup->prod);
    free(nodebackup);
    *n = NULL;
}

void deallocProductlist(Plist **headList) {
    if(emptyList(*headList))
        return;
    Plist *l = *headList;
    Node *p = l->head, *aux = NULL;
    while(p) {
        aux = p;
        p = p->next;
        deallocNode(&aux);
    }
    free(l);
    *headList = NULL;
}
