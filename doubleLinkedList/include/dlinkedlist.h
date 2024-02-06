#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list Dlist;


Dlist *initializeList();
bool emptyList(const Dlist *);
Node *createNode(int);
void appendFirst(Dlist *, int);
void appendLast(Dlist *, int);
void delNode(Dlist *, int);
void LRdisplayList(const Dlist *);
void RLdisplayList(const Dlist *);
void deallocList(Dlist **);


#endif