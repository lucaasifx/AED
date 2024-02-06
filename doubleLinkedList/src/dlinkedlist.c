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
    struct Node *head;
    struct Node *tail;
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