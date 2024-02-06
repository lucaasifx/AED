#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list Dlist;


Dlist *initializeList();
bool emptyList(Dlist *);
Node *createNode();
void appendFirst(Dlist *, int);
void deallocList(Dlist **);



#endif