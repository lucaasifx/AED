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
    return headList;
}
bool emptyList(const Dlist *headList) {
    return !headList->quantNodes;
}

Node *createNode(int key) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->key = key;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void appendFirst(Dlist *headList, int key) {
    Node *n = createNode(key);
    n->next = headList->head;

    if(emptyList(headList))
        headList->tail = n;
    else
        headList->head->prev = n;
    
    headList->head = n;
    headList->quantNodes++;
}

void appendLast(Dlist *headList, int key) {
    if(emptyList(headList))
        appendFirst(headList, key);
    else {
        Node *n = createNode(key);
        n->prev = headList->tail;
        headList->tail = headList->tail->next = n;
        headList->quantNodes++;
    }
}

void delFirst(Dlist *headList) {
    Node *backup = headList->head;
    headList->head = backup->next;
    if(headList->head)
        headList->head->prev = NULL;
    else
        headList->tail = NULL;
    free(backup);
    headList->quantNodes--;
}

void delNode(Dlist *headList, int key) {
    if(emptyList(headList))
        puts("List is empty.");
    else if(key == headList->head->key)
        delFirst(headList);
    else {
        Node *backup = headList->head, *prev = NULL;
        while(backup && backup->key != key) {
            prev = backup;
            backup = backup->next;
        }
        if(!backup)
            puts("Key isn't in list.");
        else {
            prev->next = backup->next;
            if(!prev->next)
                headList->tail = prev;
            else
                prev->next->prev = prev;
            free(backup);
            headList->quantNodes--;
        }
    }
}

void LRdisplayList(const Dlist *headList) {
    if(emptyList(headList))
        puts("List is empty.");
    else {
        printf("LRNodes: { ");
        Node *backup = headList->head;
        while(backup) {
            printf("%d, ", backup->key);
            backup = backup->next;
        }
        puts("NULL }");
    }
}

void RLdisplayList(const Dlist *headList) {
    if(emptyList(headList))
        puts("List is empty.");
    else {
        printf("RLNodes: { ");
        Node *backup = headList->tail;
        while(backup) {
            printf("%d, ", backup->key);
            backup = backup->prev;
        }
        puts("NULL }");
    }
}


void deallocList(Dlist **headList) {
    if(!emptyList(*headList)){
        Dlist *list = *headList;
        Node *backup = list->head, *prev = NULL;
        while (backup) {
            prev = backup;
            backup = backup->next;
            free(prev);
        }
        free(list);
    }
    *headList = NULL;
}

