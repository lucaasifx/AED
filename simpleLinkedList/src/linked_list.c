#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


// ********************* TAD ********************************
typedef struct node {
    int key;
    struct node *next;
} Node;

typedef struct linked_List {
    Node *head;
    Node *tail;
    int quantNodes;
} linkedList;


// ********************** FUNCTIONS ***************************
linkedList *initializeList() {
    linkedList *head_list = (linkedList *) malloc(sizeof(linkedList));
    if (!head_list) {
        puts("Allocation error!");
        exit(1);
    }
    head_list->head = NULL;
    head_list->tail = NULL;
    head_list->quantNodes = 0;
    return head_list;
}

bool emptyList(linkedList *head_list) {
    return !head_list->head && !head_list->tail;
}

Node *createNode(int key) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        puts("Allocation error!");
        exit(1);
    }
    n->key = key;
    n->next = NULL;
    return n;
}

void appendFirst(linkedList *head_list, int key) {
    Node *n = createNode(key);
    n->next = head_list->head;
    if (emptyList(head_list))
        head_list->tail = n; 
    head_list->head = n;
    head_list->quantNodes++;
}

void appendEnd(linkedList *head_list, int key) {
    if (emptyList(head_list))
        appendFirst(head_list, key);
    else {
        Node *n = createNode(key);
        head_list->tail->next = n;
        head_list->tail = n;
        head_list->quantNodes++;
    }
}

void displayList(linkedList *head_list) {
    if (emptyList(head_list))
        puts("List is empty");
    else {
        printf("Nodes: ");
        Node *current = head_list->head;
        while (current) {
            printf("[ %d | * ] ->", current->key);
            current = current->next;
        }
        printf(" NULL\n");
    }
}

void delFirst(linkedList *head_list) {
    Node *backup = head_list->head;
    head_list->head = head_list->head->next;
    free(backup);
    if(!head_list->head)
        head_list->tail = NULL;
}

void delNode(linkedList *head_list, int key) {
    if (emptyList(head_list)) 
        puts("List is empty");
    else if (key == head_list->head->key) {
        delFirst(head_list);
        head_list->quantNodes--;
    }
    else {
        Node *backup = head_list->head->next, *prev = head_list->head;
        while(backup && backup->key != key) {
            prev = backup;
            backup = backup->next;
        }
        if(!prev->next)
            puts("Key isn't in list");
        else {
            prev->next = backup->next;
            if (!prev->next)
                head_list->tail = prev;
            free(backup);
            head_list->quantNodes--;
        }
    }
}

void delAllnodes(linkedList *head_list, int key) {
    bool keyfound = false;
    if(emptyList(head_list))
        puts("List is empty!");
    else {
        if(key == head_list->head->key) {
            delFirst(head_list);
            head_list->quantNodes--;
            keyfound = true;
        }
        Node *backup = head_list->head->next, *prev = head_list->head;
        while(backup) {
            if(backup->key == key) {
                keyfound = true;
                prev->next = backup->next;

                if(backup == head_list->tail)
                    head_list->tail = prev;
                free(backup);
                backup = prev->next;
                head_list->quantNodes--;
            }
            else {
                prev = backup;
                backup = backup->next;
            }
        }
        if(!keyfound)
            puts("Key isn't in list.");
    }
}

int quantNodes(linkedList *head_list) {
    return head_list->quantNodes;
}

void deallocateList(linkedList **head_list) {
    linkedList *l = *head_list;
    Node *backup = l->head, *aux = NULL;
    while(backup) {
        aux = backup;
        backup = backup->next;
        free(aux);
    }
    free(l);
    *head_list = NULL;
}



