#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef struct node Node;
typedef struct linked_List linkedList;

linkedList *initializeList();
bool emptyList(linkedList *);
Node *createNode(int);
void appendFirst(linkedList *, int);
void appendEnd(linkedList *, int);
void delNode(linkedList *, int);
void delAllnodes(linkedList *, int key);
int quantNodes(linkedList *);
void displayList(linkedList *);
void deallocateList(linkedList **);
#endif
