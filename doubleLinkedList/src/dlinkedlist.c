#include "dlinkedlist.h"
#include <stdlib.h>
#include <stdbool.h>


// *********************** TAD ****************************
typedef struct node {
    int key;
    struct node *prev;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
    int quantNodes;
} Dlist;


// ************************ FUNCTIONS ***********************
Dlist *initializeList() {
    Dlist *headList = (Dlist *) malloc(sizeof(Dlist));
    if(!headList) {
        puts("Allocation error!");
        exit(1);
    }
    headList->head = NULL;
    headList->tail = NULL;
    headList->quantNodes = 0; 
}
bool emptyList(Dlist *headList) {
    return !headList->quantNodes;
}

Node *createNode() {
    Node *n = (Node *) malloc(sizeof(Node));
    n->key = 0;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void appendFirst(Dlist *headList, int key) {
    Node *n = createNode();
    n->next = headList->head;

    if(emptyList(headList))
        headList->tail = n;
    else
        headList->head->prev = n;
    
    headList->head = n;
    headList->quantNodes++;
}


void deallocList(Dlist **headList) {
    if(emptyList(*headList))
        puts("List is empty!");
    else {
        Dlist *list = *headList;
        Node *backup = list->head, *prev = NULL;
        while (backup) {
            prev = backup;
            backup = backup->next;
            free(prev);
        }
        free(list);
        *headList = NULL;
    }
}