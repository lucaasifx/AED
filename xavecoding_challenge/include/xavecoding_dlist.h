#ifndef XAVECODING_DLIST_H
#define XAVECODING_DLIST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct product Product;
typedef struct node Node;
typedef struct plist Plist;


Product *createProduct(int, char *, float);
Node *createNode(int, char *, float);
void displayProduct(const Product *);
Plist *initializeList();
void appendLast(Plist *, int, char *, float);
void acess(Plist *, int);
void displayList(Plist *);
bool emptyList(const Plist *);
void deallocProductlist(Plist **);

#endif